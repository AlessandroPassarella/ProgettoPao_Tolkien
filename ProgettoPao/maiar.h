#ifndef MAIAR_H
#define MAIAR_H

#include "ainur.h"

class Maiar : public Ainur{
public:
    enum Typology {puro, stregone, balrog};

    Maiar();
    Maiar(string name, int power, bool state, int age, Level level, Typology typology);

    // Metodi virtuali

    // Metodi get
    Typology getTypology() const;

    // Metodi set
    void setTypology(Typology typology);
private:
    Typology typology;
};

#endif // MAIAR_H
