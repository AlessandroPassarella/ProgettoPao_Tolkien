#ifndef AINU_H
#define AINU_H

#include "entity.h"

class Ainu : public Entity{
public:
    enum Level {higher, lower};

    Ainu();
    Ainu(string name, int power, unsigned age, Level level);

    // Metodi virtuali
    ~Ainu() = 0;
    virtual int evilness() const = 0;

    // Metodi get
    Level getLevel() const;

    // Metodi set
    void setLevel(Level level);

private:
    Level level;
};

#endif // AINU_H
