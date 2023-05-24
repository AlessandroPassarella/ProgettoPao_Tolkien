#include "maiar.h"

Maiar::Maiar(){}

Maiar::Maiar(string name, int power, unsigned age, Level level, Typology typology):
Ainur(name, power, age, level), typology(typology){}

// Metodi virtuali implementati
Entity* Maiar::clone() const{
    return new Maiar(getName(), getPower(), getAge(), getLevel(), typology);
}
int Maiar::evilness() const{
    switch (getTypology()) {
    case Maiar::Typology::pure:
        return getPower()/(getAge()+1);
    case Maiar::Typology::wizard:
        return getPower()/(getAge()+1)*2 + 50;
    case Maiar::Typology::balrog:
        return getPower()/(getAge()+1)*3 + 80;
    }
    return 0;
}

// Metodi get
Maiar::Typology Maiar::getTypology() const{
    return typology;
}

// Metodi set
void Maiar::setTypology(Typology typology){
    this->typology = typology;
}


