#include "qontainer.h"

Qontainer::Qontainer() : begin(nullptr), length(0), reserved(0) {}

Qontainer::Qontainer(const Qontainer &q) :
begin(new Entity*[q.length]), length(q.length), reserved(q.length) {
    for(unsigned i = 0;i<length; i++)
        begin[i] = q.begin[i]->clone();
}

Qontainer::~Qontainer() {
    for(unsigned i=0; i<length; i++)
        delete begin[i];
    delete[] begin;
}

void Qontainer::push(const Entity *entity){
    if (reserved==length) {
        //e se 0??
        if (reserved)
            reserved *= 2;
        else
            reserved = 10;
        Entity** arr_copy = new Entity*[reserved];
        for(unsigned i=0; i<length; i++)
            arr_copy[i] = begin[i];
        delete[] begin;
        begin = arr_copy;
    }
    begin[length] = entity->clone();
    length++;
}

void Qontainer::erase(unsigned i) {
    if (i >= length)
        throw std::out_of_range("can't pop neighbour's mail");

    delete begin[i];
    for (unsigned j=i; j<length-1; j++)
        begin[j] = begin[j+1];
    
    length--;
}

Entity* Qontainer::get(unsigned i) const {
    if (i < length)
        return begin[i];
    throw std::out_of_range("can't read neighbour's mail");
}

Entity* Qontainer::operator[](unsigned i) {
    return get(i);
}

Entity* Qontainer::operator[](unsigned i) const {
    return get(i);
}

unsigned Qontainer::size() const {
    return length;
}

Qontainer Qontainer::search(std::function<bool(const Entity*)> condition) const {
    Qontainer resultSet;
    for (unsigned i = 0; i < length; i++)
        if(condition(begin[i]))
            resultSet.push(begin[i]);
    return resultSet;
}
