#ifndef HUMANOID_H
#define HUMANOID_H

#include "entity.h"

class Humanoid : public Entity{
public:
    enum Role {hunter, knight, archer, warrior, thief, king, queen, assistant};

    Humanoid();
    Humanoid(string name, int power, unsigned age, Role role);

    // Metodi virtuali
    ~Humanoid() = 0;
    virtual int combatPower() const;

    // Metodi get
    Role getRole() const;

    // Metodi set
    void setRole(Role role);
private:
    Role role;
};

#endif // HUMANOID_H
