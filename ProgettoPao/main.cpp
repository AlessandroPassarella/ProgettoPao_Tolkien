#include <iostream>

#include "Model/races.h"
#include "serializer.h"

int main() {

//    Qontainer allBeings;
//    allBeings.push( new Vala("pippo", 5, 15, Ainu::Level::lower, Vala::Element::air) );
//    allBeings.push( new Vala("pluto", 5, 15, Ainu::Level::lower, Vala::Element::fire) );
//    allBeings.push( new Vala("topolino", 5, 15, Ainu::Level::lower, Vala::Element::air) );
//    allBeings.push( new Dwarf("gimli", 12, 120, Humanoid::Role::hunter, Dwarf::Lineage::durin) );
//    allBeings.push( new Hobbit("samgay", 12, 120, Humanoid::Role::hunter, Hobbit::Family::halfing) );
//    allBeings.push( new Elf("rollo", 1, 300, Humanoid::Role::queen, Elf::Bloodline::teleri) );
//    allBeings.push( new Human("obama binladen", 120000, 44, Humanoid::Role::king, Human::Descent::dunedian) );
//    allBeings.push( new Maia("ganjalf", 12000, 44, Ainu::Level::lower, Maia::Typology::wizard) );
//    allBeings.push( new Orc("Calippa", 12000, 44, Humanoid::Role::queen, Orc::Kind::pure) );
 
//    const char* const namefile = "C:/Users/ana_n/Desktop/ProgettoPao_Tolkien/ProgettoPao/ArmyDatabase.xml";

//    //SERIALIZE
//    QVector<Army*> armies;
//    armies.push_back(new Army("pollos", allBeings.search([](const Entity* e){return e->getAge()<100;})));
//    armies.push_back(new Army("hermanos", allBeings.search([](const Entity* e){return e->getAge()>=100;})));
//    saveArmiesToFile(armies, namefile);

//    //DESERIALIZE
//    QVector<Army*> army = parseFileAsArmy(namefile);

//    qDebug() << "found from file " << army.size() << " armies:";
//    for(int i = 0; i < army.size(); i++)
//        qDebug() << "army n." << i+1 << " called "
//                 << army[i]->getName().c_str() << " has " << army[i]->getEntities().size() << " entities";

//    return 0;
}
