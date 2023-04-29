#include "Elf.h"

Elf::Elf(){}

Elf::Elf(string name, int power, bool state, int age, Ability ability, Bloodline bloodline):
Humanoids(name, power, state, age, ability), bloodline(bloodline){}

// Metodi get
Elf::Bloodline Elf::getBloodline() const{
    return bloodline;
}

// Metodi set
void Elf::setBloodline(Bloodline bloodline){
    this->bloodline = bloodline;
}
