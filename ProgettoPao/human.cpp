#include "human.h"

Human::Human(){}

Human::Human(string name, int power, int age, Role role, Descent descent):
Humanoid(name, power, age, role), descent(descent){}

// Metodi get
Human::Descent Human::getDescent() const{
    return descent;
}

// Metodi set
void Human::setDescent(Descent descent){
    this->descent = descent;
}


