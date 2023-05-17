#include <iostream>

#include "races.h"

using std::cout;
using std::endl;

int main() {
    
    Qontainer allBeings;
    allBeings.push( new Valar("pippo", 5, 15, Ainur::Level::lower, Valar::Element::air) );
    allBeings.push( new Valar("pluto", 5, 15, Ainur::Level::lower, Valar::Element::fire) );
    allBeings.push( new Valar("topolino", 5, 15, Ainur::Level::lower, Valar::Element::air) );
    allBeings.push( new Dwarf("gimli", 12, 120, Humanoid::Role::hunter, Dwarf::Lineage::durin) );
    allBeings.push( new Hobbit("samgay", 12, 120, Humanoid::Role::hunter, Hobbit::Family::halfing) );
    allBeings.push( new Elf("rollo", 1, 300, Humanoid::Role::queen, Elf::Bloodline::teleri) );
    allBeings.push( new Human("obama binladen", 120000, 44, Humanoid::Role::king, Human::Descent::dunedian) );
    allBeings.push( new Maiar("ganjalf", 12000, 44, Ainur::Level::lower, Maiar::Typology::wizard) );
    allBeings.push( new Orc("calippa", 12000, 44, Humanoid::Role::queen, Orc::Kind::pure) );
 
    
    Qontainer q2 = allBeings.search(
        [] (Entity const* x) {
            return dynamic_cast<Valar const*>(x) && (dynamic_cast<Valar const*>(x)->getElement() == Valar::Element::air);
        }
    );

    Army army1("armataGiovani", allBeings.search(
        [] (Entity const* x) {  return x->getAge()<18; }
    ));
    Army army2("armataVecchi", allBeings.search(
        [] (Entity const* x) {  return x->getAge()>=18; }
    ));

    cout << "GIOVANI:\n";
    for(unsigned i = 0; i < army1.getEntities().size();i++)
        cout << army1.getEntities()[i]->getName() << endl;
    cout << "\nVECCHI:\n";
    for(unsigned i = 0; i < army2.getEntities().size();i++)
        cout << army2.getEntities()[i]->getName() << endl;


    return 0;
}
