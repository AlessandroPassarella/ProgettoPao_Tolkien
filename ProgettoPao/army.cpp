#include "army.h"

Army::Army() : _name(), _entities()
{

}

Army::Army(const std::string &name, const Qontainer<Entity *>& entities) : _name(name), _entities(entities)
{

}

string Army::getName() const
{
    return _name;
}

Entity *Army::getEntity(unsigned int index) const
{
    return _entities.get(index);
}

const Qontainer<Entity *> &Army::getEntities() const
{
    return _entities;
}

Qontainer<Entity *> &Army::getEntities()
{
    return _entities;
}

void Army::addEntity(Entity * const entity)
{
    _entities.push(entity);
}

void Army::deleteEntity(unsigned int i)
{
    _entities.erease(i);
}
