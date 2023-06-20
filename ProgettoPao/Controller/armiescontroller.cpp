#include "armiescontroller.h"

ArmiesController::ArmiesController(DataSave& dataSave):
    dataSave(dataSave)
{
}


void ArmiesController::deleteArmy(int index) {
    dataSave.removeArmy(index);
}


QVector<Army*> ArmiesController::getArmies() {
    return dataSave.getArmies();
}
