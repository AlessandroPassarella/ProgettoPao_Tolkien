#ifndef HUMANOIDS_H
#define HUMANOIDS_H

#include "entity.h"

class Humanoids : public Entity{
public:
    enum Ability {}; //da inserire

    Humanoids();
    Humanoids(string name, int power, bool state, int age, Ability ability);

    // Metodi virtuali

    // Metodi get
    Ability getAbility() const;

    // Metodi set
    void setAbility(Ability ability);
private:
    Ability ability; 
};

#endif // HUMANOIDS_H
