#include "ainu.h"

Ainu::Ainu(){}
Ainu::~Ainu() = default;

Ainu::Ainu(string name, int power, unsigned age, Level level):
Entity(name, power, age), level(level){}

// Metodi get
Ainu::Level Ainu::getLevel() const{
    return level;
}

// Metodi set
void Ainu::setLevel(Level level){
    this->level = level;
}
