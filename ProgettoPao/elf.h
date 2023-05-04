#ifndef ELF_H
#define ELF_H

#include "humanoid.h"

class Elf : public Humanoid{
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
