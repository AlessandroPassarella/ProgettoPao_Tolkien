#ifndef MAIAR_H
#define MAIAR_H

#include "ainur.h"

class Maiar : public Ainur
{
private:
    enum tipo {puro, stregone, balrog};
public:
    Maiar();
};

#endif // MAIAR_H
