#include "entitiescontroller.h"


EntitiesController::EntitiesController(DataSave& dataSave) :
    dataSave(dataSave) {
}

Entity* EntitiesController::getEntity(int army, int index) {
    return dataSave.getArmy(army)->getEntity(index);
}

void EntitiesController::deleteEntity(int army, int index){

}

void EntitiesController::addEntity(int army, QString name){

}

QString EntitiesController::getName(int army) {
    return QString::fromStdString(dataSave.getArmies()[army]->getName());
}
