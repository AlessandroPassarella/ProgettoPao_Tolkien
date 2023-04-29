#include "humanoids.h"

Humanoids::Humanoids(){}

Humanoids::Humanoids(string name, int power, bool state, int age, Ability ability):
Entity(name, power, state, age), ability(ability){}

// Metodi get
Humanoids::Ability Humanoids::getAbility() const{
    return ability;
}

// Metodi set
void Humanoids::setAbility(Ability ability){
    this->ability = ability;
}