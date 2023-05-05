#include "qontainer.h"

void Qontainer::push(const Entity &entity){
        if (reserved == length) {
            reserved *= 2;
            Entity* arr_copy = new Entity[reserved];
            for(int i=0; i<length; i++){
                arr_copy[i] = begin[i];
            }
            delete[] begin;
            begin=arr_copy;
        }
        begin[length] = entity; 
        length++;
    }

void Qontainer::pop(unsigned int i){
    if (i < length){
        if (i=0){
            begin = begin+1;
        }
        for (int j=i; j<length-1; j++){
            begin[i] = begin[i+1];
        }
        length--;
    }
    throw "IndexOutOfBoundexception, can't pop neighbour's mail";
}

Entity& Qontainer::get(unsigned int i) const{
    if (i < length)
        return begin[length];
    throw "IndexOutOfBoundexception, can't read neighbour's mail";
}