#ifndef ORCHI_H
#define ORCHI_H

#include "humanoids.h"

class Orchi : public Humanoids
{
private:
    enum tipo {puri, gobli, orchetti};
public:
    Orchi();
};

#endif // ORCHI_H
