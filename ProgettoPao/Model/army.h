#ifndef ARMY_H
#define ARMY_H

#include "../qontainer.h"
#include <string>
using std::string;

class Army {
public:
    Army(const string& name, const Qontainer& entities = Qontainer());

    //metodi
    string getName() const;
    void addEntity(Entity* const entity);
    void deleteEntity(unsigned int entity);
    unsigned size() const;
    Entity* get(unsigned i) const;

private:
    const string name;
    Qontainer entities;
};

#endif // ARMY_H
