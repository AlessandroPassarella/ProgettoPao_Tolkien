#include "datasave.h"
#include "serializer.h"

DataSave::DataSave() {}

void DataSave::open(QString filename) {
    armies = parseFileAsArmy(filename);
}

void DataSave::save(QString filename) const {
    saveArmiesToFile(armies, filename);
}

QVector<Army*> DataSave::getArmies() const {
    return armies;
}

Army *DataSave::getArmy(unsigned int i) const {
    return armies[i];
}

void DataSave::addArmy(Army * const army) {
    armies.push_back(army);
}

void DataSave::removeArmy(unsigned int i) {
    armies.remove(i);
}
