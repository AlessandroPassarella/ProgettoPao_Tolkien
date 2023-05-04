#ifndef ORC_H
#define ORC_H

#include "humanoid.h"

class Orc : public Humanoid {
public:
    enum Kind {puri, goblin, orchetti};

    Orc();
    Orc(string name, int power, bool state, int age, Ability ability, Kind Kind);

    // Metodi virtuali

    // Metodi get
    Kind getKind() const;

    // Metodi set
    void setKind(Kind kind);

private:
    Kind kind;
};

#endif // ORC_H
