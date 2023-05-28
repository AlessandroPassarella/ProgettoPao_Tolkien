#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Model/model.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString openedFileName;
    Model model;

private slots:
    void openFile();
    void saveFile();

};
#endif // MAINWINDOW_H
