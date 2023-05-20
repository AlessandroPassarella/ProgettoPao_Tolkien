#include "serializer.h"

void parseEntity(QXmlStreamWriter& stream, const Entity* entity) {
    stream.writeStartElement("entity");
    if (const Humanoid* humanoid = dynamic_cast<const Humanoid*>(entity)) {

        if (const Elf* elf = dynamic_cast<const Elf*>(humanoid)) {
            stream.writeAttribute("type", "Elf");
            stream.writeTextElement("bloodline", QString::number(static_cast<int>(elf->getBloodline())));
        } else
            if (const Hobbit* hobbit = dynamic_cast<const Hobbit*>(humanoid)) {
            stream.writeAttribute("type", "Hobbit");
            stream.writeTextElement("family", QString::number(static_cast<int>(hobbit->getFamily())));
        } else
            if (const Dwarf* dwarf = dynamic_cast<const Dwarf*>(humanoid)) {
            stream.writeAttribute("type", "Dwarf");
            stream.writeTextElement("lineage", QString::number(static_cast<int>(dwarf->getLineage())));
        } else
            if (const Orc* orc = dynamic_cast<const Orc*>(humanoid)) {
            stream.writeAttribute("type", "Orc");
            stream.writeTextElement("kind", QString::number(static_cast<int>(orc->getKind())));
        } else
            if (const Human* human = dynamic_cast<const Human*>(humanoid)) {
            stream.writeAttribute("type", "Human");
            stream.writeTextElement("descent", QString::number(static_cast<int>(human->getDescent())));
        }
        stream.writeTextElement("role", QString::number(static_cast<int>(humanoid->getRole())));
    } else{

        if (const Valar* valar = dynamic_cast<const Valar*>(entity)) {
            stream.writeAttribute("type", "Valar");
            stream.writeTextElement("element", QString::number(static_cast<int>(valar->getElement())));
        } else if (const Maiar* maiar = dynamic_cast<const Maiar*>(entity)) {
            stream.writeAttribute("type", "Maiar");
            stream.writeTextElement("typology", QString::number(static_cast<int>(maiar->getTypology())));
        }
        stream.writeTextElement("level", QString::number(static_cast<int>((dynamic_cast<const Ainur*>(entity))->getLevel())));

    }
    stream.writeTextElement("name", QString::fromStdString(entity->getName()));
    stream.writeTextElement("power", QString::number(entity->getPower()));
    stream.writeTextElement("age", QString::number(entity->getAge()));
    stream.writeEndElement();
}

void parseArmy(QXmlStreamWriter& stream, Army* army){
    stream.writeStartElement("army");
    stream.writeAttribute("name", QString::fromStdString(army->getName()));

    Qontainer entities = army->getEntities();

    for(unsigned i=0; i<entities.size(); i++){
        parseEntity(stream,entities.get(i));
    }
    stream.writeEndElement();
}

void f(Army* army){
    QFile file("C:/Users/ana_n/Desktop/ProgettoPao_Tolkien/ProgettoPao/ArmyDatabase.xml");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    parseArmy(xmlWriter, army);

    xmlWriter.writeEndDocument();
    file.close();
}

/*
Army* parseFileAsArmy(string filename) {

}

    /*

    -new Army
    -leggi e setta
    -foreach file.army.entities
      --parseQualcosaAsEntity



Entity* parseQualcosaAsEntity(const string xml_string) {

}
*/
