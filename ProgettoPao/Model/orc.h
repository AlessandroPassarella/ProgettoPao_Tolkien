#ifndef ORC_H
#define ORC_H

#include "humanoid.h"

class Orc : public Humanoid {
public:
    enum Kind {pure, goblin, white};

    Orc();
    Orc(string name, int power, unsigned age, Role role, Kind Kind);

    // Metodi virtuali
    Entity* clone() const;
    int combatPower() const;
    
    // Metodi get
    Kind getKind() const;

    // Metodi set
    void setKind(Kind kind);

private:
    Kind kind;
};

#endif // ORC_H
