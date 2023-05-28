#include "mainwindow.h"
#include "serializer.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    openFile();

    QWidget* w = new QWidget(this);
    resize(550, 550);

    QVBoxLayout* l1 = new QVBoxLayout;
    w->setLayout(l1);

    QLabel* label = new QLabel("ciao");
    l1->addWidget(label);

    QMenuBar* menu = new QMenuBar(w);

    QMenu* fileMenu = new QMenu("File");
    QAction* newFileAction = new QAction("New File", fileMenu);
    QAction* openFileAction = new QAction("Open File", fileMenu);
    QAction* saveFileAction = new QAction("Save File", fileMenu);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);

    QMenu* editMenu = new QMenu("Edit");
    QAction* cleanEditAction = new QAction("Clean", editMenu);
    QAction* restoreEditAction = new QAction("Restore Army", editMenu);
    editMenu->addAction(cleanEditAction);
    editMenu->addAction(restoreEditAction);

    menu->addMenu(fileMenu);
    menu->addMenu(editMenu);

    //QHBoxLayout* mainLayout = new QHBoxLayout(w);

    connect(openFileAction, &QAction::triggered, this, &MainWindow::openFile);
}

MainWindow::~MainWindow() {}

void MainWindow::openFile() {
    openedFileName = QFileDialog::getOpenFileName(this, "Apri salvataggio", "/home", "Salvataggio armate (*.xml)").toStdString().c_str();
    if(openedFileName == "")  return;
    model.open(openedFileName);
    qDebug() << "Opened file " << openedFileName;
}
