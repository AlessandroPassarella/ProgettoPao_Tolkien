#include "serializer.h"

// Serialize
void parseEntity(QXmlStreamWriter& stream, const Entity* entity) {
    stream.writeStartElement("entity");
    if (const Humanoid* humanoid = dynamic_cast<const Humanoid*>(entity)) {

        if (const Elf* elf = dynamic_cast<const Elf*>(humanoid)) {
            stream.writeAttribute("type", "Elf");
            stream.writeTextElement("bloodline", QString::number(static_cast<int>(elf->getBloodline())));
        } else if (const Hobbit* hobbit = dynamic_cast<const Hobbit*>(humanoid)) {
            stream.writeAttribute("type", "Hobbit");
            stream.writeTextElement("family", QString::number(static_cast<int>(hobbit->getFamily())));
        } else if (const Dwarf* dwarf = dynamic_cast<const Dwarf*>(humanoid)) {
            stream.writeAttribute("type", "Dwarf");
            stream.writeTextElement("lineage", QString::number(static_cast<int>(dwarf->getLineage())));
        } else if (const Orc* orc = dynamic_cast<const Orc*>(humanoid)) {
            stream.writeAttribute("type", "Orc");
            stream.writeTextElement("kind", QString::number(static_cast<int>(orc->getKind())));
        } else if (const Human* human = dynamic_cast<const Human*>(humanoid)) {
            stream.writeAttribute("type", "Human");
            stream.writeTextElement("descent", QString::number(static_cast<int>(human->getDescent())));
        }
        stream.writeTextElement("role", QString::number(static_cast<int>(humanoid->getRole())));
    } else{

        if (const Valar* vala = dynamic_cast<const Valar*>(entity)) {
            stream.writeAttribute("type", "Vala");
            stream.writeTextElement("element", QString::number(static_cast<int>(vala->getElement())));
        } else if (const Maiar* maia = dynamic_cast<const Maiar*>(entity)) {
            stream.writeAttribute("type", "Maia");
            stream.writeTextElement("typology", QString::number(static_cast<int>(maia->getTypology())));
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

void saveArmiesToFile(QVector<Army*> armies, const char* const filename){
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("armies");
    for(int i=0; i<armies.size(); i++)
        parseArmy(xmlWriter, armies[i]);
    xmlWriter.writeStartElement("armies");
    xmlWriter.writeEndDocument();
    file.close();
}

// Deserialize

// Classi astratte
void setEntityProperties(Entity* entity, QString property, QStringView value) {
    if(property == "name")
        entity->setName(value.toString().toStdString());
    else if(property == "power")
        entity->setPower(value.toInt());
    else if(property == "age")
        entity->setAge(value.toInt());
}

void setHumanoidProperties(Humanoid* humanoid, QString property, QStringView value) {
    if (property == "role")
        humanoid->setRole(static_cast<Humanoid::Role>(value.toInt()));
    else setEntityProperties(humanoid, property, value);
}
void setAinuProperties(Ainur* ainu, QString property, QStringView value) {
    if (property == "level")
        ainu->setLevel(static_cast<Ainur::Level>(value.toInt()));
    else setEntityProperties(ainu, property, value);
}

// Classi concrete
void setElfProperty(Elf* elf, QString property, QStringView value) {
    if (property == "bloodline")
        elf->setBloodline(static_cast<Elf::Bloodline>(value.toInt()));
    else setHumanoidProperties(elf, property, value);
}
void setHobbitProperty(Hobbit* hobbit, QString property, QStringView value) {
    if (property == "family")
        hobbit->setFamily(static_cast<Hobbit::Family>(value.toInt()));
    else setHumanoidProperties(hobbit, property, value);
}
void setDwarfProperty(Dwarf* dwarf, QString property, QStringView value) {
    if (property == "lineage")
        dwarf->setLineage(static_cast<Dwarf::Lineage>(value.toInt()));
    else setHumanoidProperties(dwarf, property, value);
}
void setOrcProperty(Orc* orc, QString property, QStringView value) {
    if (property == "kind")
        orc->setKind(static_cast<Orc::Kind>(value.toInt()));
    else setHumanoidProperties(orc, property, value);
}
void setHumanProperty(Human* human, QString property, QStringView value) {
    if (property == "descent")
        human->setDescent(static_cast<Human::Descent>(value.toInt()));
    else setHumanoidProperties(human, property, value);
}
void setValarProperty(Valar* vala, QString property, QStringView value) {
    if (property == "element")
        vala->setElement(static_cast<Valar::Element>(value.toInt()));
    else setAinuProperties(vala, property, value);
}
void setMaiarProperty(Maiar* maia, QString property, QStringView value) {
    if (property == "typology")
        maia->setTypology(static_cast<Maiar::Typology>(value.toInt()));
    else setAinuProperties(maia, property, value);
}


QVector<Army*> parseFileAsArmy(const char* const filename) {
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader xmlReader(&file);

    xmlReader.readNextStartElement();
    xmlReader.readNextStartElement();

    QVector<Army*> vec;

    while(xmlReader.name().toString() != "armies") {
        QString armyName = xmlReader.attributes().value("name").toString();
        Qontainer entities;
        QString classType;
        while(true) {

            xmlReader.readNextStartElement();

            classType = xmlReader.attributes().value("type").toString();
            xmlReader.readNextStartElement();

            if(classType=="Elf"){
                Elf elf;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setElfProperty(&elf, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&elf);
            }else if(classType=="Hobbit"){
                Hobbit hobbit;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setHobbitProperty(&hobbit, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&hobbit);
            }else if(classType=="Dwarf"){
                Dwarf dwarf;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setDwarfProperty(&dwarf, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&dwarf);
            }else if(classType=="Orc"){
                Orc orc;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setOrcProperty(&orc, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&orc);
            }else if(classType=="Human"){
                Human human;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setHumanProperty(&human, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&human);
            }else if(classType=="Vala"){
                Valar valar;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setValarProperty(&valar, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&valar);
            }else if(classType=="Maia"){
                Maiar maiar;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setMaiarProperty(&maiar, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&maiar);
            }else break;
        }
        vec.push_back(new Army(armyName.toStdString(), entities));
    }
    return vec;
}
