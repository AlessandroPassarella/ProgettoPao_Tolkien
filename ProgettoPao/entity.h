#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
private:
    int potere;
    bool stato;
    int anni;
public:
    Entity();
    virtual ~Entity() = 0;
};

#endif // ENTITY_H
