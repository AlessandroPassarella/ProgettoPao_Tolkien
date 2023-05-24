#include "valar.h"

Valar::Valar(){}

Valar::Valar(string name, int power, unsigned age, Level level, Element element):
Ainur(name, power, age, level), element(element){}

// Metodi virtuali implementati
Entity* Valar::clone() const{
    return new Valar(getName(), getPower(), getAge(), getLevel(), element);
}
int Valar::evilness() const{
    return (getName()=="Morgoth")*100;
}

// Metodi get
Valar::Element Valar::getElement() const{
    return element;
}

// Metodi set
void Valar::setElement(Element element){
    this->element = element;
}

