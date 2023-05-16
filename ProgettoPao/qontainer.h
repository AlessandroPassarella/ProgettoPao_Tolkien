#include <iostream>
#include <functional>
#include <stdexcept>
#include "entity.h"


class Qontainer
{
private:
    Entity ** begin;
    unsigned int length, reserved;

public:
    Qontainer();

    Qontainer(const Qontainer &q);

    virtual ~Qontainer();

    void push(const Entity *entity);

    void pop(unsigned int i);

    Entity* get(unsigned int i) const;

    unsigned size() const;

    Qontainer search(std::function<bool(const Entity*)> condition) const;

};
