#ifndef _ENTITYVECTOR_H
#define _ENTITYVECTOR_H
#include <iostream>
#include <functional>
#include <stdexcept>
#include "Model/entity.h"


class EntityVector {
private:
    Entity ** begin;
    unsigned length, reserved;

public:
    EntityVector();

    EntityVector(const EntityVector &q);

    virtual ~EntityVector();

    void push(const Entity *entity);

    void erase(unsigned i);

    Entity* get(unsigned i) const;
    Entity* operator[](unsigned i);
    Entity* operator[](unsigned i) const;

    unsigned size() const;


    struct IndexedSearchResult {
        Entity* e;
        unsigned index;
    };
    struct SearchResults {
        IndexedSearchResult* results;
        unsigned size;
    };
    SearchResults search(std::function<bool(const Entity*)> condition) const;

};

#endif
