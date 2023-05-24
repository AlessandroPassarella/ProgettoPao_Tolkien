#include "army.h"

Army::Army(const std::string &name, const Qontainer& entities) : 
    name(name), entities(entities){}

string Army::getName() const{
    return name;
}

Qontainer& Army::getEntities(){
    return entities;
}

void Army::addEntity(Entity * const entity)
{
    entities.push(entity);
}

void Army::deleteEntity(unsigned int entity)
{
    entities.erase(entity);
}

