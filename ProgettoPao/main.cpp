#include <iostream>

#include "races.h"
#include "serializer.h"

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
    allBeings.push( new Orc("Calippa", 12000, 44, Humanoid::Role::queen, Orc::Kind::pure) );
 
    const char* const namefile = "C:/Users/ana_n/Desktop/ProgettoPao_Tolkien/ProgettoPao/ArmyDatabase.xml";

    Army* army = parseFileAsArmy(namefile);
    cout << army->getName() << endl;
    Qontainer qontainer = army->getEntities();

    return 0;
}
