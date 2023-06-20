#ifndef ARMIESCONTROLLER_H
#define ARMIESCONTROLLER_H

#include "datasave.h"
#include <QWidget>

class ArmiesController
{
    DataSave& dataSave;

public:
    ArmiesController(DataSave& dataSave);
    QWidget* getView();
    void deleteArmy(int index);
    void addArmy(QString name);
    QVector<Army*> getArmies();
};

#endif // ARMIESCONTROLLER_H
