#include "armiescontroller.h"

ArmiesController::ArmiesController(DataSave& dataSave):
    dataSave(dataSave) {
}

void ArmiesController::deleteArmy(int index) {
    dataSave.removeArmy(index);
}

void ArmiesController::addArmy(QString name) {
    Army* newArmy = new Army(name.toStdString());
    dataSave.addArmy(newArmy);
}


QVector<Army*> ArmiesController::getArmies() {
    return dataSave.getArmies();
}
