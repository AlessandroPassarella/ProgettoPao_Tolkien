#include "Model/races.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>
#include <QStringView>
#include <QMetaEnum>
using std::string;

void parseEntity(QXmlStreamWriter& stream, const Entity* entity);

void parseArmy(QXmlStreamWriter& stream, Army* army);

void saveArmiesToFile(QVector<Army*> armies, const char* const filename);

QVector<Army*> parseFileAsArmy(const char* const filename);
