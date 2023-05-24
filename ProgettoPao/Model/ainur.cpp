#include "ainur.h"

Ainur::Ainur(){}
Ainur::~Ainur() = default;

Ainur::Ainur(string name, int power, unsigned age, Level level):
Entity(name, power, age), level(level){}

// Metodi get
Ainur::Level Ainur::getLevel() const{
    return level;
}

// Metodi set
void Ainur::setLevel(Level level){
    this->level = level;
}
