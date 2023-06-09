#ifndef ARMIESVIEW_H
#define ARMIESVIEW_H

#include "Controller/armiescontroller.h"
#include <QTableWidget>
#include <QWidget>

class ArmiesView : public QWidget {
    Q_OBJECT

private:
    QTableWidget* armiesTable;

    ArmiesController* armiesController;

public:
    ArmiesView(QWidget *parent, ArmiesController* armiesController);

    void load();

};

#endif // ARMIESVIEW_H
