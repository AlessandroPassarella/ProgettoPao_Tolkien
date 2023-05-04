#ifndef HUMAN_H
#define HUMAN_H

#include "humanoid.h"

class Human : public Humanoid {
public:
    enum Descent {dunedian, mediani, bardi};

    Human();
    Human(string name, int power, bool state, int age, Ability ability, Descent descent);

    // Metodi virtuali

    // Metodi get
    Descent getDescent() const;

    // Metodi set
    void setDescent(Descent descent);

private:
    Descent descent;
};

#endif // HUMAN_H
