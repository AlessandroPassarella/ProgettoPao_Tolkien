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

        if (const Vala* vala = dynamic_cast<const Vala*>(entity)) {
            stream.writeAttribute("type", "Vala");
            stream.writeTextElement("element", QString::number(static_cast<int>(vala->getElement())));
        } else if (const Maia* maia = dynamic_cast<const Maia*>(entity)) {
            stream.writeAttribute("type", "Maia");
            stream.writeTextElement("typology", QString::number(static_cast<int>(maia->getTypology())));
        }
        stream.writeTextElement("level", QString::number(static_cast<int>((dynamic_cast<const Ainu*>(entity))->getLevel())));

    }
    stream.writeTextElement("name", QString::fromStdString(entity->getName()));
    stream.writeTextElement("power", QString::number(entity->getPower()));
    stream.writeTextElement("age", QString::number(entity->getAge()));
    stream.writeEndElement();
}

void parseArmy(QXmlStreamWriter& stream, Army* army){
    stream.writeStartElement("army");
    stream.writeAttribute("name", QString::fromStdString(army->getName()));

    for(unsigned i=0; i<army->size(); i++){
        parseEntity(stream, army->getEntity(i));
    }
    stream.writeEndElement();
}

void saveArmiesToFile(QVector<Army*> armies, QString filename){
    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("armies");
    for(unsigned i=0; i<armies.size(); i++)
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
void setAinuProperties(Ainu* ainu, QString property, QStringView value) {
    if (property == "level")
        ainu->setLevel(static_cast<Ainu::Level>(value.toInt()));
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
void setValaProperty(Vala* vala, QString property, QStringView value) {
    if (property == "element")
        vala->setElement(static_cast<Vala::Element>(value.toInt()));
    else setAinuProperties(vala, property, value);
}
void setMaiaProperty(Maia* maia, QString property, QStringView value) {
    if (property == "typology")
        maia->setTypology(static_cast<Maia::Typology>(value.toInt()));
    else setAinuProperties(maia, property, value);
}


QVector<Army*> parseFileAsArmy(QString filename) {
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
                Vala vala;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setValaProperty(&vala, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&vala);
            }else if(classType=="Maia"){
                Maia maia;
                QString tagName = xmlReader.name().toString();
                while (tagName != "entity") {
                    xmlReader.readNext();
                    setMaiaProperty(&maia, tagName, xmlReader.text());
                    xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    tagName = xmlReader.name().toString();
                }
                entities.push(&maia);
            }else break;
        }
        vec.push_back(new Army(armyName.toStdString(), entities));
    }
    return vec;
}
