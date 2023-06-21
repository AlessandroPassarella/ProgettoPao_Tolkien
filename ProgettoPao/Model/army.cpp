#include "army.h"

Army::Army(const std::string &name, const Qontainer& entities) :
    name(name), entities(entities){}

string Army::getName() const{
    return name;
}

void Army::addEntity(Entity * const entity) {
    entities.push(entity);
}

void Army::deleteEntity(unsigned int entity) {
    entities.erase(entity);
}

unsigned Army::size() const {
    return entities.size();
}

Entity* Army::getEntity(unsigned i) const {
    return entities[i];
}

Qontainer Army::getEntities() const
{
    return entities;
}

int Army::getTotalPower() const{
    int totPower = 0;
    for(unsigned i=0; i < entities.size(); i++){
        totPower += entities[i]->getPower();
    }
    return totPower;
}

