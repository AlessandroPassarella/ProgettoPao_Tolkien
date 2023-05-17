#ifndef AINUR_H
#define AINUR_H

#include "entity.h"

class Ainur : public Entity{
public:
    enum Level {higher, lower};

    Ainur();
    Ainur(string name, int power, int age, Level level);

    // Metodi virtuali
    ~Ainur() = 0;

    // Metodi get
    Level getLevel() const;

    // Metodi set
    void setLevel(Level level);

private:
    Level level;
};

#endif // AINUR_H
