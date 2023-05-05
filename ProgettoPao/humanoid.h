#ifndef HUMANOID_H
#define HUMANOID_H

#include "entity.h"

class Humanoid : public Entity{
public:
    enum Role {hunter, knight, archer, worrior, thief, king, queen, assistant}; //da inserire

    Humanoid();
    Humanoid(string name, int power, int age, Role role);

    // Metodi virtuali

    // Metodi get
    Role getRole() const;

    // Metodi set
    void setRole(Role role);
private:
    Role role;
};

#endif // HUMANOID_H
