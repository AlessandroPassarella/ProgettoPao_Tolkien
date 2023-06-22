#ifndef _QONTAINER_H
#define _QONTAINER_H
#include <iostream>
#include <functional>
#include <stdexcept>
#include "Model/entity.h"


class Qontainer {
private:
    Entity ** begin;
    unsigned length, reserved;

public:
    Qontainer();

    Qontainer(const Qontainer &q);

    virtual ~Qontainer();

    void push(const Entity *entity);

    void erase(unsigned i);

    Entity* get(unsigned i) const;
    Entity* operator[](unsigned i);
    Entity* operator[](unsigned i) const;

    unsigned size() const;


    struct SearchResult {
        Entity* e;
        unsigned index;
    };

    std::vector<SearchResult> search(std::function<bool(const Entity*)> condition) const;

};

#endif
