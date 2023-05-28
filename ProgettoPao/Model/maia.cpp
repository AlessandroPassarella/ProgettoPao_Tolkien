#include "maia.h"

Maia::Maia(){}

Maia::Maia(string name, int power, unsigned age, Level level, Typology typology):
Ainu(name, power, age, level), typology(typology){}

// Metodi virtuali implementati
Entity* Maia::clone() const{
    return new Maia(getName(), getPower(), getAge(), getLevel(), typology);
}
int Maia::evilness() const{
    switch (getTypology()) {
    case Maia::Typology::pure:
        return getPower()/(getAge()+1);
    case Maia::Typology::wizard:
        return getPower()/(getAge()+1)*2 + 50;
    case Maia::Typology::balrog:
        return getPower()/(getAge()+1)*3 + 80;
    }
    return 0;
}

// Metodi get
Maia::Typology Maia::getTypology() const{
    return typology;
}

// Metodi set
void Maia::setTypology(Typology typology){
    this->typology = typology;
}


