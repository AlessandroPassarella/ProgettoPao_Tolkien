#include <iostream>
#include <functional>
#include <stdexcept>
#include "entity.h"

template<class T>
class Qontainer
{
private:
    T *begin;
    unsigned int length, reserved;

public:
    Qontainer();

    Qontainer(const Qontainer &q);

    ~Qontainer();

    void push(const T &entity);

    void pop(unsigned int i);

    T& get(unsigned int i) const;

    unsigned size() const;

    Qontainer search(std::function<bool(const T*)> condition) const;

};


template<class T>
Qontainer<T>::Qontainer() : begin(nullptr), length(0), reserved(0) {}

template<class T>
Qontainer<T>::Qontainer(const Qontainer &q) :
begin(new T[q.length]), length(q.length), reserved(q.length) {
    for(unsigned i = 0;i<length; i++)
        begin[i] = q.begin[i];
}

template<class T>
Qontainer<T>::~Qontainer() {
    delete[] begin;
}

template<class T>
void Qontainer<T>::push(const T &entity){
    if (reserved==length) {
        //e se 0??
        if (reserved)
            reserved *= 2;
        else
            reserved = 10;
        T* arr_copy = new T[reserved];
        for(unsigned i=0; i<length; i++)
            arr_copy[i] = begin[i];
        delete[] begin;
        begin = arr_copy;
    }
    begin[length] = entity; 
    length++;
}

template<class T>
unsigned Qontainer<T>::size() const {
    return length;
}

template<class T>
void Qontainer<T>::pop(unsigned int i) {
    if (i >= length)
        throw std::out_of_range("can't pop neighbour's mail");
    
    for (unsigned j=i; j<length-1; j++)
        begin[j] = begin[j+1];
    
    length--;
}

template<class T>
T& Qontainer<T>::get(unsigned int i) const {
    if (i < length)
        return begin[i];
    throw std::out_of_range("can't read neighbour's mail");
}

template<class T>
Qontainer<T> Qontainer<T>::search(std::function<bool(const T*)> condition) const {
    Qontainer<T> resultSet;
    for (unsigned int i = 0; i < length; i++)
        if(condition(&begin[i]))
            resultSet.push(begin[i]);
    return resultSet;
}