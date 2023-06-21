#ifndef ENTITIESCONTROLLER_H
#define ENTITIESCONTROLLER_H

#include "datasave.h"
#include <QWidget>

class EntitiesController
{

public:
    EntitiesController();
    void deleteEntity(int index);
    void addEntity(QString name);
};

#endif // ENTITIESCONTROLLER_H
