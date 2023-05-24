#ifndef MAIAR_H
#define MAIAR_H

#include "ainur.h"

class Maiar : public Ainur {
public:
    enum Typology {pure, wizard, balrog};

    Maiar();
    Maiar(string name, int power, unsigned age, Level level, Typology typology);

    // Metodi virtuali implementati
    Entity* clone() const;
    int evilness() const;

    // Metodi get
    Typology getTypology() const;

    // Metodi set
    void setTypology(Typology typology);
private:
    Typology typology;
};

#endif // MAIAR_H
