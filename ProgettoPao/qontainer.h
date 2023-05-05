#include "entity.h"

class Qontainer
{
private:
    Entity *begin;
    unsigned int length, reserved;

public:
    Qontainer() : begin(nullptr), length(0) {}

    void push(const Entity &entity);

    void pop(unsigned int i);

    Entity& get(unsigned int i) const;

    bool search() const;

    /*
    copia profonda
    Entity* copia(){
        Entity* arr_copy = new Entity[reserved];
        for(int i=0; i<length; i++){
            arr_copy[i] = begin[i];
        }
        return arr_copy;

    }
    */

};