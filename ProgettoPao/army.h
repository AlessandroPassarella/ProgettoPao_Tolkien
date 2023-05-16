#ifndef ARMY_H
#define ARMY_H

#include "qontainer.h"
#include <string>
using std::string;

class Army
{
public:
    Army();
    Army(const string& name, const Qontainer<Entity*>& entities = Qontainer<Entity*>());

    //metodi
    string getName() const;
    Entity* getEntity(unsigned int index) const;
    const Qontainer<Entity*>& getEntities() const;
    Qontainer<Entity*>& getEntities();
    void addEntity(Entity* const entity);
    void deleteEntity(unsigned int i);

private:
    string _name;
    Qontainer<Entity*> _entities;
};

#endif // ARMY_H
