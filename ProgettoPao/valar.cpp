#include "valar.h"

Valar::Valar(){}
Valar::Valar(string name, int power, bool state, int age, Level level, Element element):
Ainur(name, power, state, age, level), element(element){}

// Metodi get
Valar::Element Valar::getElement() const{
    return element;
}

// Metodi set
void Valar::setElement(Element element){
    this->element = element;
}

