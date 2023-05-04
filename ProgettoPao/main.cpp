#include <iostream>

#include "valar.h"
#include "ainur.h"


int main() {
    std::cout << "nmiasdsdgu" << std::endl;
    Entity * valar = new Valar("pippo", 5, 1, 15, Ainur::Level::lower, Valar::Element::air);
    std::cout<< valar->getName();
}
