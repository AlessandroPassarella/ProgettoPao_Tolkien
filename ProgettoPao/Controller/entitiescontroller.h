#ifndef ENTITIESCONTROLLER_H
#define ENTITIESCONTROLLER_H

#include "datasave.h"
#include <QWidget>

class EntitiesController
{
private:
    DataSave& dataSave;

public:
    EntitiesController(DataSave& dataSave);
    Entity* getEntity(int army, int index);
    const EntityVector& getEntities(int i);
    void deleteEntity(int army, int index);
    void addEntity(int army, Entity* entity);
    QString getName(int army);
};

#endif // ENTITIESCONTROLLER_H
