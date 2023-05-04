#ifndef HUMANOID_H
#define HUMANOID_H

#include "entity.h"

class Humanoid : public Entity{
public:
    enum Ability {}; //da inserire

    Humanoid();
    Humanoid(string name, int power, bool state, int age, Ability ability);

    // Metodi virtuali

    // Metodi get
    Ability getAbility() const;

    // Metodi set
    void setAbility(Ability ability);
private:
    Ability ability; 
};

#endif // HUMANOID_H
