#ifndef MAIA_H
#define MAIA_H

#include "ainu.h"

class Maia : public Ainu {
public:
    enum Typology {pure, wizard, balrog};

    Maia();
    Maia(string name, int power, unsigned age, Level level, Typology typology);

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

#endif // MAIA_H
