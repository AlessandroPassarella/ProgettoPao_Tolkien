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
    Qontainer& getEntities();
    void addEntity(Entity* const entity);
    void deleteEntity(unsigned int entity);

private:
    const string name;
    Qontainer entities;
};

#endif // ARMY_H
