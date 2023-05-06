#include <iostream>

#include "valar.h"
#include "ainur.h"
#include "qontainer.h"

int main() {
    Entity * valar1 = new Valar("pippo", 5, 15, Ainur::Level::lower, Valar::Element::air);
    Entity * valar2 = new Valar("pluto", 5, 15, Ainur::Level::lower, Valar::Element::fire);
    Entity * valar3 = new Valar("topolino", 5, 15, Ainur::Level::lower, Valar::Element::air);
    
    Qontainer<Entity*> f;
    f.push( valar1 );
    f.push( valar2 );
    f.push( valar3 );

    std::cout << "@@@" << f.get(1)->getName() << '\n';
    std::cout << "@@@" << dynamic_cast<Valar*>(f.get(1))->getName() << '\n';
    
    Qontainer<Entity*> q2 = f.search(
        [] (Entity*const* x) {
            return (dynamic_cast<Valar*const>(*x)->getElement() == Valar::Element::air);
        }
    );

    for (unsigned i = 0; i < q2.size(); i++)
        std::cout << q2.get(i)->getName() << " farts into the wind" << std::endl;

    return 0;
}
