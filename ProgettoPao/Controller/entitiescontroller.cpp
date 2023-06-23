#include "entitiescontroller.h"


EntitiesController::EntitiesController(DataSave& dataSave) :
    dataSave(dataSave) {
}

Entity* EntitiesController::getEntity(int army, int index) {
    return dataSave.getArmy(army)->getEntity(index);
}

void EntitiesController::deleteEntity(int army, int index){
    dataSave.getArmy(army)->deleteEntity(index);
}

void EntitiesController::addEntity(int army, Entity* entity){
    dataSave.addEntity(army, entity);
}

QString EntitiesController::getName(int army) {
    return QString::fromStdString(dataSave.getArmies()[army]->getName());
}

const Qontainer& EntitiesController::getEntities(int i) {
    return dataSave.getArmies()[i]->getEntities();
}
