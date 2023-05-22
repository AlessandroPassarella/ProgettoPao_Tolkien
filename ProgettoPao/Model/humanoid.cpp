#include "humanoid.h"

Humanoid::Humanoid(){}
Humanoid::~Humanoid() = default;

Humanoid::Humanoid(string name, int power, unsigned age, Role role):
Entity(name, power, age), role(role){}

//Metodi virutali
int Humanoid::combatPower() const {
    return getPower() + getAge()/10;
}

// Metodi get
Humanoid::Role Humanoid::getRole() const{
    return role;
}

// Metodi set
void Humanoid::setRole(Role role){
    this->role = role;
}
