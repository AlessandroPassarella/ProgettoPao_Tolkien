#include "maiar.h"

Maiar::Maiar(){}

Maiar::Maiar(string name, int power, bool state, int age, Level level, Typology typology):
Ainur(name, power, state, age, level), typology(typology){}

// Metodi get
Maiar::Typology Maiar::getTypology() const{
    return typology;
}

// Metodi set
void Maiar::setTypology(Typology typology){
    this->typology = typology;
}
