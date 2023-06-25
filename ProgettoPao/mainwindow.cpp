#include "mainwindow.h"
#include "serializer.h"
#include <QFileDialog>
#include <QMenuBar>
#include <QtWidgets>
#include <QtWidgets>

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    QMessageBox msgBox;
    msgBox.setText("New save or open old one?");
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

  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  centralWidget->setLayout(mainLayout);

  // MENU

  QMenuBar *menu = new QMenuBar;

  QMenu *fileMenu = new QMenu("File");
  QAction *newFileAction = new QAction("New File", fileMenu);
  newFileAction->setShortcut(QKeySequence::New);
  QAction *openFileAction = new QAction("Open File", fileMenu);
  openFileAction->setShortcut(QKeySequence::Open);
  QAction *saveFileAction = new QAction("Save File", fileMenu);
  saveFileAction->setShortcut(QKeySequence::Save);
  fileMenu->addAction(newFileAction);
  fileMenu->addAction(openFileAction);
  fileMenu->addAction(saveFileAction);


  QMenu *editMenu = new QMenu("Edit");
  QAction *cleanEditAction = new QAction("Clean armies", editMenu);
  editMenu->addAction(cleanEditAction);

  QAction *creditsAction = new QAction("Credits", editMenu);
  cleanEditAction->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT |  Qt::Key_X));

  menu->addMenu(fileMenu);
  menu->addMenu(editMenu);
  menu->addAction(creditsAction);


  menu->setStyleSheet("QMenuBar { background-color: #f3f3f3; border-bottom: 1px solid #ccc;} QMenuBar::item {border-right: 1px solid #ccc; border-left: 1px solid #ccc; border-top: 1px solid #ccc; padding:3px 10px 3px 10px;}");

  mainLayout->addWidget(menu);


  connect(newFileAction, &QAction::triggered, this, &MainWindow::newFile);
  connect(openFileAction, &QAction::triggered, this, &MainWindow::openFile);
  connect(saveFileAction, &QAction::triggered, this, [this](){this->model.save(openedFileName);});

  connect(cleanEditAction, &QAction::triggered, this, [this](){
      this->model.clearArmies();
      this->openArmiesView();
  });

  connect(creditsAction, &QAction::triggered, this, [this](){
      QMessageBox::information(this, "Credits", "Lavoro a cura di Ana Maria Niagu e Alessandro Passarella");
  });

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
      this, tr("Open Directory"), "/home/student",
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
      QFileDialog::getOpenFileName(this, "Open Save", "/home/student",
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
  resize(650, 450);
  entitiesView->show();
  entitiesView->load(i);
}

void MainWindow::closeEvent(QCloseEvent *exit){
  QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit",
                                                            "Are you sure you want to Exit? Remember to save before exiting! ",
                                                            QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::Yes)
      exit->accept();
  else
      exit->ignore();
};
