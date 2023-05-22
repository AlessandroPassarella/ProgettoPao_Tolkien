#ifndef HUMAN_H
#define HUMAN_H

#include "humanoid.h"

class Human : public Humanoid {
public:
    enum Descent {dunedian, medianum, bard};

    Human();
    Human(string name, int power, unsigned age, Role role, Descent descent);

    // Metodi virtuali
    Entity* clone() const;

    // Metodi get
    Descent getDescent() const;

    // Metodi set
    void setDescent(Descent descent);

private:
    Descent descent;
};

#endif // HUMAN_H
