#include "Elf.h"

Elf::Elf(){}

Elf::Elf(string name, int power, int age, Role role, Bloodline bloodline):
Humanoid(name, power, age, role), bloodline(bloodline){}

// Metodi get
Elf::Bloodline Elf::getBloodline() const{
    return bloodline;
}

// Metodi set
void Elf::setBloodline(Bloodline bloodline){
    this->bloodline = bloodline;
}
