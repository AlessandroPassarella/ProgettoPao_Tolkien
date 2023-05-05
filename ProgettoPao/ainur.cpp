#include "ainur.h"

Ainur::Ainur(){}

Ainur::Ainur(string name, int power, int age, Level level):
Entity(name, power, age), level(level){}

// Metodi virtuali

// Metodi get
Ainur::Level Ainur::getLevel() const{
    return level;
}

// Metodi set
void Ainur::setLevel(Level level){
    this->level = level;
}
