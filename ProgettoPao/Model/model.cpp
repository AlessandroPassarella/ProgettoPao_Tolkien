#include "model.h"
#include "serializer.h"

Model::Model() {}

void Model::open(QString filename) {
    armies = parseFileAsArmy(filename);
}

void Model::save(QString filename) const {
    saveArmiesToFile(armies, filename);
}

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
