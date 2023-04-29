#include "hobbit.h"

Hobbit::Hobbit(){}

Hobbit::Hobbit(string name, int power, bool state, int age, Ability ability, Family family):
Humanoids(name, power, state, age, ability), family(family){}

// Metodi get
Hobbit::Family Hobbit::getFamily() const{
    return family;
}

// Metodi set
void Hobbit::setFamily(Family family){
    this->family = family;
}
