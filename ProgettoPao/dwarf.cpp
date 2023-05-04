#include "dwarf.h"

Dwarf::Dwarf(){}

Dwarf::Dwarf(string name, int power, bool state, int age, Ability ability, Lineage lineage):
Humanoid(name, power, state, age, ability), lineage(lineage){}

// Metodi get
Dwarf::Lineage Dwarf::getLineage() const{
    return lineage;
}

// Metodi set
void Dwarf::setLineage(Lineage lineage){
    this->lineage = lineage;
}
