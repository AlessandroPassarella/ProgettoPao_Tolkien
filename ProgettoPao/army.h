#ifndef ARMY_H
#define ARMY_H

#include "qontainer.h"
#include <string>
using std::string;

class Army {
public:
    Army(const string& name, const Qontainer& entities = Qontainer());

    //metodi
    string getName() const;
    Qontainer& getEntities();

private:
    const string name;
    Qontainer entities;
};

#endif // ARMY_H
