#include "model.h"

Model::Model()
{

}

vector<Army *> Model::getArmies() const
{
    return armies;
}

Army *Model::getArmy(unsigned int idx) const
{
    return armies[idx];
}

void Model::addArmy(Army * const army)
{
    armies.push_back(army);
}

void Model::removeArmy(unsigned int army)
{
    vector<Army*>::iterator it = armies.begin();

    for (unsigned int i = 0; i < army; i++)
        it++;

    armies.erase(it);
}
