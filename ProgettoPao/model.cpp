#include "model.h"

Model::Model() { }

QVector<Army*> Model::getArmies() const {
    return armies;
}

Army *Model::getArmy(unsigned int i) const {
    return armies[i];
}

void Model::addArmy(Army * const army) {
    armies.push_back(army);
}

void Model::removeArmy(unsigned int i) {
    armies.remove(i);
}
