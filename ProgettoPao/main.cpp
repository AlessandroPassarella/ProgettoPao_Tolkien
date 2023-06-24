#include <iostream>
#include <QApplication>

#include "Model/races.h"
#include "serializer.h"
#include "mainwindow.h"

int GUI_launch(int argc, char *argv[]);
void noGUI_launch();

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    MainWindow main;
    main.show();

    return a.exec();
}
