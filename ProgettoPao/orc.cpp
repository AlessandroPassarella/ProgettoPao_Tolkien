#include "orc.h"

Orc::Orc() {}

Orc::Orc(string name, int power, int age, Role role, Kind kind) :
    Humanoid(name, power, age, role), kind(kind) {}

// Metodi get
Orc::Kind Orc::getKind() const {
    return kind;
}

// Metodi set
void Orc::setKind(Kind kind) {
    this->kind = kind;
}

Entity *Orc::clone() const {
    return new Orc(getName(), getPower(), getAge(), getRole(), kind);
}