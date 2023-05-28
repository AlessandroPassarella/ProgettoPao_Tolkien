#include "Model/races.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>

void parseEntity(QXmlStreamWriter& stream, const Entity* entity);

void parseArmy(QXmlStreamWriter& stream, Army* army);

void saveArmiesToFile(QVector<Army*> armies, QString filename);

QVector<Army*> parseFileAsArmy(QString filename);
