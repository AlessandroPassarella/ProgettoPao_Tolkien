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
    void openArmiesView();
    void openEntitiesView(int i);

private:
    QString openedFileName;
    DataSave model;
    ArmiesController* armiesController;
    EntitiesController* entitiesController;
    ArmiesView* armiesView;
    EntitiesView* entitiesView;

private slots:
    void newFile(bool justOpenedProgram = false);
    void openFile(bool justOpenedProgram = false);
};
#endif // MAINWINDOW_H
