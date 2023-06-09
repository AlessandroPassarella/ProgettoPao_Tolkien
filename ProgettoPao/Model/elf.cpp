#include "elf.h"

Elf::Elf(){}

Elf::Elf(string name, int power, unsigned age, Role role, Bloodline bloodline):
Humanoid(name, power, age, role), bloodline(bloodline){}

Entity* Elf::clone() const{
    return new Elf(getName(), getPower(), getAge(), getRole(), bloodline);
}

// Metodi get
Elf::Bloodline Elf::getBloodline() const{
    return bloodline;
}

// Metodi set
void Elf::setBloodline(Bloodline bloodline){
    this->bloodline = bloodline;
}
