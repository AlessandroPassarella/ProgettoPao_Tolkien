#ifndef ENTITIESCONTROLLER_H
#define ENTITIESCONTROLLER_H

#include "datasave.h"
#include <QWidget>

class EntitiesController
{
    DataSave& dataSave;

public:
    EntitiesController(DataSave &dataSave);
    void deleteEntity(int index);
    void addEntity(QString name);
};

#endif // ENTITIESCONTROLLER_H
