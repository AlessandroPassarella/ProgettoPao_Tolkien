#include "human.h"

Human::Human(){}

Human::Human(string name, int power, bool state, int age, Ability ability, Descent descent):
Humanoids(name, power, state, age, ability), descent(descent){}

// Metodi get
Human::Descent Human::getDescent() const{
    return descent;
}

// Metodi set
void Human::setDescent(Descent descent){
    this->descent = descent;
}


