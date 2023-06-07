#include <iostream>
#include <QApplication>

#include "Model/races.h"
#include "serializer.h"
#include "mainwindow.h"
#include "view.h"

int GUI_launch(int argc, char *argv[]);
void noGUI_launch();

int main(int argc, char *argv[]) {

    const bool GUI = true;
    if (GUI)
        GUI_launch(argc,argv);
    else
        noGUI_launch();
}

int GUI_launch(int argc, char *argv[]) {

    QApplication a(argc, argv);

    MainWindow main;
    main.show();

    return a.exec();
}

void noGUI_launch(){

    Qontainer allBeings;
    allBeings.push( new Vala("pippo", 5, 15, Ainu::Level::lower, Vala::Element::air) );
    allBeings.push( new Vala("pluto", 5, 15, Ainu::Level::lower, Vala::Element::fire) );
    allBeings.push( new Vala("topolino", 5, 15, Ainu::Level::lower, Vala::Element::air) );
    allBeings.push( new Dwarf("gimli", 12, 120, Humanoid::Role::hunter, Dwarf::Lineage::durin) );
    allBeings.push( new Hobbit("samgay", 12, 120, Humanoid::Role::hunter, Hobbit::Family::halfing) );
    allBeings.push( new Elf("rollo", 1, 300, Humanoid::Role::queen, Elf::Bloodline::teleri) );
    allBeings.push( new Human("obama binladen", 120000, 44, Humanoid::Role::king, Human::Descent::dunedian) );
    allBeings.push( new Maia("ganjalf", 12000, 44, Ainu::Level::lower, Maia::Typology::wizard) );
    allBeings.push( new Orc("Calippa", 12000, 44, Humanoid::Role::queen, Orc::Kind::pure) );

    const char* const namefile = "C:/Users/ana_n/Desktop/ProgettoPao_Tolkien/ProgettoPao/ArmyDatabase.xml";

    //SERIALIZE
//    QVector<Army*> armies;
//    armies.push_back(new Army("pollos", allBeings.search([](const Entity* e){return e->getAge()<100;})));
//    armies.push_back(new Army("hermanos", allBeings.search([](const Entity* e){return e->getAge()>=100;})));
//    saveArmiesToFile(armies, namefile);

    Model model; // usando model funziona ed ha piu senso (secondo me)

    model.addArmy(new Army("pollos", allBeings.search([](const Entity* e){return e->getAge()<100;})));
    model.addArmy(new Army("hermanos", allBeings.search([](const Entity* e){return e->getAge()>=100;})));
    saveArmiesToFile(model.getArmies(), namefile);

    //DESERIALIZE
//    QVector<Army*> army = parseFileAsArmy(namefile);

//    qDebug() << "found from file " << army.size() << " armies:";
//    for(int i = 0; i < army.size(); i++)
//        qDebug() << "army n." << i+1 << " called "
//                 << army[i]->getName().c_str() << " has " << army[i]->size() << " entities";

    model.open(namefile);

    qDebug() << "found from file " << model.getArmies().size() << " armies:";
    for(int i = 0; i < model.getArmies().size(); i++)
        qDebug() << "army n." << i+1 << " called "
                 << model.getArmy(i)->getName().c_str() << " has " << model.getArmy(i)->size() << " entities";

}
