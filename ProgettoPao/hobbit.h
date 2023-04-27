#ifndef HOBBIT_H
#define HOBBIT_H

#include "humanoids.h"

class Hobbit : public Humanoids
{
private:
    enum famiglia {Halfing, pelopiedi, sturoi};
public:
    Hobbit();
};

#endif // HOBBIT_H
