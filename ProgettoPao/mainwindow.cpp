#include "mainwindow.h"
#include "View/armiesview.h"
#include "serializer.h"
#include <QFileDialog>
#include <QMenuBar>
#include <QtWidgets>

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  openFile();

  // CENTRAL LAYOUT AND HEADER

  QWidget *centralWidget = new QWidget(this);
  resize(550, 550);

  setCentralWidget(centralWidget);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  centralWidget->setLayout(mainLayout);

  QHBoxLayout *labelLayout = new QHBoxLayout;
  QLabel *label = new QLabel("<h1>Armies</h1>");
  //label->setFixedWidth(300);
  // label->setFont(QFont("Arial", 22));
  labelLayout->addWidget(label, 0, Qt::AlignCenter);
  mainLayout->addLayout(labelLayout);

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
  connect(saveFileAction, &QAction::triggered, this, &MainWindow::saveFile);

  // TABLE ARMIES

  armiesController = new ArmiesController(model);
  armiesView = new ArmiesView(this, armiesController);
  mainLayout->addWidget(armiesView);
}

void MainWindow::openFile() {
  openedFileName =
      QFileDialog::getOpenFileName(this, "Apri salvataggio", "/home",
                                   "Salvataggio armate (*.xml)")
          .toStdString()
          .c_str();
  if (openedFileName == "")
    return;
  model.open(openedFileName);
  qDebug() << "Opened file " << openedFileName;
}

void MainWindow::saveFile() { model.save(openedFileName); }
