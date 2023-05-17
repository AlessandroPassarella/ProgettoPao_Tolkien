#include "army.h"

Army::Army(const string &name) : name(name), entities() {}

Army::Army(const std::string &name, const Qontainer& entities) : 
    name(name), entities(entities){}

string Army::getName() const{
    return name;
}

Qontainer &Army::getEntities(){
    return entities;
}

