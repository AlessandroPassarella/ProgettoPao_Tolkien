#include <sstream>
#include <string>

#include "races.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <QMetaEnum>
using std::string;

void parseEntity(QXmlStreamWriter& stream, const Entity* entity);

void parseArmy(QXmlStreamWriter& stream, Army* army);

void saveArmyToFile(Army* army, const char* const filename);

Army* parseFileAsArmy(const char* const filename);

Entity* parseQualcosaAsEntity(const string xml_string);
