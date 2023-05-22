#ifndef VALA_H
#define VALA_H

#include "ainu.h"

class Vala : public Ainu{
public:
    enum Element {air, water, earth, fire, death};

    Vala();
    Vala(string name, int power, unsigned age, Level level, Element element);

    // Metodi virtuali
    Entity* clone() const;
    int evilness() const;
    
    // Metodi get
    Element getElement() const;

    // Metodi set
    void setElement(Element element);

private:
    Element element;
};

#endif // VALA_H
