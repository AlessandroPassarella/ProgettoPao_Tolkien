#include "mainwindow.h"
#include "serializer.h"
#include <QFileDialog>
#include <QMenuBar>
#include <QtWidgets>

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    QMessageBox msgBox;
    msgBox.setText("New save or open old one?:");
    msgBox.addButton("New File", QMessageBox::AcceptRole);
    msgBox.addButton("Open File", QMessageBox::AcceptRole);
    msgBox.addButton("Cancel", QMessageBox::RejectRole);

    int choice = msgBox.exec();

    if (choice == 0)
        newFile(true);
    else if (choice == 1)
        openFile(true);
    else if (choice == 2)
        exit(0);


  // CENTRAL LAYOUT AND HEADER

  // ridimensiona finestrra con mouse drag?
  // setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  centralWidget->setLayout(mainLayout);

  // MENU

  QMenuBar *menu = new QMenuBar(centralWidget);

  QMenu *fileMenu = new QMenu("File");
  QAction *newFileAction = new QAction("New File", fileMenu);
  QAction *openFileAction = new QAction("Open File", fileMenu);
  QAction *saveFileAction = new QAction("Save File", fileMenu);
  fileMenu->addAction(newFileAction);
  fileMenu->addAction(openFileAction);
  fileMenu->addAction(saveFileAction);

  QMenu *editMenu = new QMenu("Edit");
  QAction *cleanEditAction = new QAction("Clean", editMenu);
  QAction *restoreEditAction = new QAction("Restore Army", editMenu);
  editMenu->addAction(cleanEditAction);
  editMenu->addAction(restoreEditAction);

  menu->addMenu(fileMenu);
  menu->addMenu(editMenu);

  connect(newFileAction, &QAction::triggered, this, &MainWindow::newFile);
  connect(openFileAction, &QAction::triggered, this, &MainWindow::openFile);
  connect(saveFileAction, &QAction::triggered, this, [this](){this->model.save(openedFileName);});


  // TABLE ARMIES

  armiesController = new ArmiesController(model);
  armiesView = new ArmiesView(this, armiesController);
  mainLayout->addWidget(armiesView);

  entitiesController = new EntitiesController(model);
  entitiesView = new EntitiesView(this, entitiesController);
  mainLayout->addWidget(entitiesView);

  openArmiesView();
}

void MainWindow::newFile(bool justOpenedProgram) {
  QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "/home",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  if (dir == "") {
      if (justOpenedProgram)
          exit(0);
      return;
  }
  bool ok;
  QString fileName = QInputDialog::getText(this, "Select File name",
                               "Name :", QLineEdit::Normal, "", &ok);
  if (!ok)
      exit(0);

  fileName = dir + '/' + fileName;
  if (!fileName.endsWith(".xml"))
      fileName += ".xml";
  QFile file( fileName );
  QTextStream stream( &file );
  file.open(QIODevice::ReadWrite);
  stream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?><armies></armies>";
  file.close();
  openedFileName = fileName;
  model.open(openedFileName);
  if(!justOpenedProgram)
      armiesView->load();
}

void MainWindow::openFile(bool justOpenedProgram) {
  openedFileName =
      QFileDialog::getOpenFileName(this, "Open Save", "/home",
                                   "Army save file (*.xml)")
          .toStdString()
          .c_str();
  if (openedFileName == "") {
      exit(0);
  }
  model.open(openedFileName);
  if(!justOpenedProgram)
      armiesView->load();
}

void MainWindow::openArmiesView() {
  entitiesView->hide();
  resize(350, 400);
  armiesView->show();
  armiesView->load();
}

void MainWindow::openEntitiesView(int i) {
  armiesView->hide();
  resize(650, 550);
  entitiesView->show();
  entitiesView->load(i);
}
