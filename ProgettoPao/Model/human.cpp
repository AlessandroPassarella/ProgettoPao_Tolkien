#include "human.h"

Human::Human(){}

Human::Human(string name, int power, unsigned age, Role role, Descent descent):
Humanoid(name, power, age, role), descent(descent){}

// Metodi get
Human::Descent Human::getDescent() const{
    return descent;
}

// Metodi set
void Human::setDescent(Descent descent){
    this->descent = descent;
}

Entity* Human::clone() const {
    return new Human(getName(), getPower(), getAge(), getRole(), descent);
}
