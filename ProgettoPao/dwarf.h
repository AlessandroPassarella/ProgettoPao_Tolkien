#ifndef DWARF_H
#define DWARF_H

#include "humanoid.h"

class Dwarf : public Humanoid
{
public:
    enum Lineage {durin, barbafiamma, nerachiave, vastifascio, pugniferro, pediroccia, barbadura};

    Dwarf();
    Dwarf(string name, int power, int age, Role role, Lineage lineage);

    // Metodi virtuali
    
    // Metodi get
    Lineage getLineage() const;

    // Metodi set
    void setLineage(Lineage lineage);

private:
    Lineage lineage;
};

#endif // DWARF_H
