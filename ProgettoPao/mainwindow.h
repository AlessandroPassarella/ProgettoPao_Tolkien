#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "View/armiesview.h"
#include "View/entitiesview.h"

#include "datasave.h"
#include "Controller/armiescontroller.h"
#include "Controller/entitiescontroller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString openedFileName;
    DataSave model;
    ArmiesController* armiesController;
    EntitiesController* entitiesController;
    ArmiesView* armiesView;
    EntitiesView* entitiesView;
    void openArmiesView();
    void openEntitiesView(int i);

private slots:
    void openFile();
};
#endif // MAINWINDOW_H
