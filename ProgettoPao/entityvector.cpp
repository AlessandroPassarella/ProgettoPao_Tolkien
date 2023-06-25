#include "entityvector.h"

EntityVector::EntityVector() : begin(nullptr), length(0), reserved(0) {}

EntityVector::EntityVector(const EntityVector &q) :
begin(new Entity*[q.length]), length(q.length), reserved(q.length) {
    for(unsigned i = 0;i<length; i++)
        begin[i] = q.begin[i]->clone();
}

EntityVector::~EntityVector() {
    for(unsigned i=0; i<length; i++)
        delete begin[i];
    delete[] begin;
}

void EntityVector::push(const Entity *entity){
    if (reserved==length) {
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

void EntityVector::erase(unsigned i) {
    if (i >= length)
        throw std::out_of_range("can't pop neighbour's mail");

    delete begin[i];
    for (unsigned j=i; j<length-1; j++)
        begin[j] = begin[j+1];

    length--;
}

Entity* EntityVector::get(unsigned i) const {
    if (i < length)
        return begin[i];
    throw std::out_of_range("can't read neighbour's mail");
}

Entity* EntityVector::operator[](unsigned i) {
    return get(i);
}

Entity* EntityVector::operator[](unsigned i) const {
    return get(i);
}

unsigned EntityVector::size() const {
    return length;
}

EntityVector::SearchResults EntityVector::search(std::function<bool(const Entity*)> condition) const {
    SearchResults results;
    int count = 0;
    for (unsigned i = 0; i < length; i++)
        if(condition(begin[i]))
            count++;

    results.size = count;
    results.results = new IndexedSearchResult[count];
    int j = 0;
    for (unsigned i = 0; i < length; i++)
        if(condition(begin[i])) {
            results.results[j].e = get(i);
            results.results[j].index = i;
            j++;
        }
    return results;
}
