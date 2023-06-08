#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "Model/model.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString openedFileName;
    Model model;
    QTableWidget* armiesTable; //usare armiesview, in mainwindow.cpp togliere le parti per creare la armiestable che si fa in armiesview.cpp


private slots:
    void openFile();
    void saveFile();

};
#endif // MAINWINDOW_H
