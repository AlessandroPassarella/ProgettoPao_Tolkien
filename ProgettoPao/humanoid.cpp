#include "humanoid.h"

Humanoid::Humanoid(){}

Humanoid::Humanoid(string name, int power, bool state, int age, Ability ability):
Entity(name, power, state, age), ability(ability){}

// Metodi get
Humanoid::Ability Humanoid::getAbility() const{
    return ability;
}

// Metodi set
void Humanoid::setAbility(Ability ability){
    this->ability = ability;
}
