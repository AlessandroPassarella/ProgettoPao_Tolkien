#ifndef HOBBIT_H
#define HOBBIT_H

#include "humanoid.h"

class Hobbit : public Humanoid{
public:
    enum Family {halfing, harfoots, sturoi};

    Hobbit();
    Hobbit(string name, int power, bool state, int age, Ability ability, Family family);

    // Metodi virtuali

    // Metodi get
    Family getFamily() const;

    // Metodi set
    void setFamily(Family family);

private:
    Family family; 
};

#endif // HOBBIT_H
