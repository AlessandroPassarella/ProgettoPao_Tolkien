#ifndef UOMINI_H
#define UOMINI_H

#include "humanoids.h"

class Uomini : public Humanoids
{
private:
    enum discendenza {dunedian, mediani, bardi};
public:
    Uomini();
};

#endif // UOMINI_H
