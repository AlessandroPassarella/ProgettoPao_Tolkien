#include "mainwindow.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* w = new QWidget(this);

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

    connect(openFileAction, &QAction::triggered, this, &MainWindow::openNewFile);
}

MainWindow::~MainWindow() {}

void MainWindow::openNewFile() {
    qDebug() << "@@@@@@@@@@@@@@@@@";
}
