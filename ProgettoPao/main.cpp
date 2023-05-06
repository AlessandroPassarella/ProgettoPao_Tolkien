#include <iostream>

#include "valar.h"
#include "ainur.h"
#include "qontainer.h"

int main() {
    Entity * valar1 = new Valar("pippo", 5, 15, Ainur::Level::lower, Valar::Element::air);
    Entity * valar2 = new Valar("pluto", 5, 15, Ainur::Level::lower, Valar::Element::fire);
    Entity * valar3 = new Valar("topolino", 5, 15, Ainur::Level::lower, Valar::Element::air);
    
    Qontainer f;
    f.push( *valar1 );
    f.push( *valar2 );
    f.push( *valar3 );
    
    Qontainer q2 = f.search(
        [] (const Entity* x) { return (x->getName()[0] == 'p'); }
    );

    for (unsigned i = 0; i < q2.size(); i++)
        std::cout << q2.get(i).getName() << " begins with 'P'" << std::endl;

    return 0;
}
