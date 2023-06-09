#include "hobbit.h"

Hobbit::Hobbit(){}

Hobbit::Hobbit(string name, int power, unsigned age, Role role, Family family):
Humanoid(name, power, age, role), family(family){}

Entity* Hobbit::clone() const{
    return new Hobbit(getName(), getPower(), getAge(), getRole(), family);
}

// Metodi get
Hobbit::Family Hobbit::getFamily() const{
    return family;
}

// Metodi set
void Hobbit::setFamily(Family family){
    this->family = family;
}
