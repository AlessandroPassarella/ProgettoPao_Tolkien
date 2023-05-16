#include "dwarf.h"

Dwarf::Dwarf(){}

Dwarf::Dwarf(string name, int power, int age, Role role, Lineage lineage):
Humanoid(name, power, age, role), lineage(lineage){}

Entity* Dwarf::clone() const{
    return new Dwarf(getName(), getPower(), getAge(), getRole(), lineage);
}

// Metodi get
Dwarf::Lineage Dwarf::getLineage() const{
    return lineage;
}

// Metodi set
void Dwarf::setLineage(Lineage lineage){
    this->lineage = lineage;
}
