#include "qontainer.h"


Qontainer::Qontainer() : begin(nullptr), length(0), reserved(0) {}


void Qontainer::push(const Entity &entity){
    if (reserved==length) {
        //e se 0??
        if (reserved)
            reserved *= 2;
        else
            reserved = 10;
        Entity* arr_copy = new Entity[reserved];
        for(unsigned i=0; i<length; i++)
            arr_copy[i] = begin[i];
        delete[] begin;
        begin = arr_copy;
    }
    begin[length] = entity; 
    length++;
}

unsigned Qontainer::size() const {
    return length;
}

void Qontainer::pop(unsigned int i){
    if (i >= length)
        throw "IndexOutOfBoundexception, can't pop neighbour's mail";
    
    for (unsigned j=i; j<length-1; j++)
        begin[j] = begin[j+1];
    
    length--;
}

Entity& Qontainer::get(unsigned int i) const{
    if (i < length)
        return begin[i];
    throw "IndexOutOfBoundexception, can't read neighbour's mail";
}

Qontainer Qontainer::search(std::function<bool(const Entity*)> condition) const {
    Qontainer resultSet;
    
    for (unsigned int i = 0; i < length; i++) {
        if(condition(&begin[i])) {
            resultSet.push(begin[i]);
        }
    }
    return resultSet;
}