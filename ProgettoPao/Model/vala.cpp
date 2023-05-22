#include "vala.h"

Vala::Vala(){}

Vala::Vala(string name, int power, unsigned age, Level level, Element element):
Ainu(name, power, age, level), element(element){}

// Metodi virtuali implementati
Entity* Vala::clone() const{
    return new Vala(getName(), getPower(), getAge(), getLevel(), element);
}
int Vala::evilness() const{
    return (getName()=="Morgoth")*100;
}

// Metodi get
Vala::Element Vala::getElement() const{
    return element;
}

// Metodi set
void Vala::setElement(Element element){
    this->element = element;
}

