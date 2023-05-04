#include "orc.h"

Orc::Orc(){}

Orc::Orc(string name, int power, bool state, int age, Ability ability, Kind kind):
Humanoid(name, power, state, age, ability), kind(kind){}

// Metodi get
Orc::Kind Orc::getKind() const{
    return kind;
}

// Metodi set
void Orc::setKind(Kind kind){
    this->kind = kind;
}

