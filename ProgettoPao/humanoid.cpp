#include "humanoid.h"

Humanoid::Humanoid(){}

Humanoid::Humanoid(string name, int power, int age, Role role):
Entity(name, power, age), role(role){}

// Metodi get
Humanoid::Role Humanoid::getRole() const{
    return role;
}

// Metodi set
void Humanoid::setRole(Role role){
    this->role = role;
}
