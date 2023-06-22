#include "mainwindow.h"
#include "serializer.h"
#include <QFileDialog>
#include <QMenuBar>
#include <QtWidgets>

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  openFile();

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

void MainWindow::openFile() {
  openedFileName =
      QFileDialog::getOpenFileName(this, "Apri salvataggio", "/home",
                                   "Salvataggio armate (*.xml)")
          .toStdString()
          .c_str();
  if (openedFileName == "") {
    openFile();
    return;
  }
  model.open(openedFileName);
  qDebug() << "Opened file " << openedFileName;
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
