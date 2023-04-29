#ifndef HOBBIT_H
#define HOBBIT_H

#include "humanoids.h"

class Hobbit : public Humanoids{
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
