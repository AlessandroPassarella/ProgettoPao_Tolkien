#ifndef ELFI_H
#define ELFI_H

#include "humanoids.h"

class Elfi : public Humanoids
{
private:
    enum stirpe {vanyar, noldor, teleri, avari};
public:
    Elfi();
};

#endif // ELFI_H
