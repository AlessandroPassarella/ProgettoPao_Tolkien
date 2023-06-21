#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "View/armiesview.h"
#include "View/entitiesview.h"

#include "datasave.h"
#include "Controller/armiescontroller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString openedFileName;
    DataSave model;
    ArmiesController* armiesController;
    ArmiesView* armiesView;
    EntitiesView* entitiesView;

private slots:
    void openFile();
    void saveFile();

};
#endif // MAINWINDOW_H
