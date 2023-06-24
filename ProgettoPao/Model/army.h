#ifndef ARMY_H
#define ARMY_H

#include "../entityvector.h"
#include <string>
using std::string;

class Army {
public:
    Army(const string& name, const EntityVector& entities = EntityVector());

    //metodi
    string getName() const;
    void addEntity(Entity* const entity);
    void deleteEntity(unsigned int entity);
    unsigned size() const;
    Entity* getEntity(unsigned i) const;
    const EntityVector& getEntities() const;

    int getTotalPower() const;

private:
    const string name;
    EntityVector entities;
};

#endif // ARMY_H
