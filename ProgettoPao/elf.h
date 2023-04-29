#ifndef ELF_H
#define ELF_H

#include "humanoids.h"

class Elf : public Humanoids{
public:
    enum Bloodline {vanyar, noldor, teleri, avari};

    Elf();
    Elf(string name, int power, bool state, int age, Ability ability, Bloodline bloodline);

    // Metodi virtuali

    // Metodi get
    Bloodline getBloodline() const;

    // Metodi set
    void setBloodline(Bloodline bloodline);

private:
    Bloodline bloodline;
};

#endif // ELF_H
