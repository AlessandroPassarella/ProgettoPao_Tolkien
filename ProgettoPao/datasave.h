#ifndef DATASAVE_H
#define DATASAVE_H

#include <qontainer.h>
#include <Model/army.h>
#include <QVector>

using std::vector;

class DataSave
{
public:
    DataSave();

    void open(QString filename);
    void save(QString filename) const;

    QVector<Army*> getArmies() const;
    Army* getArmy(unsigned int i) const;

    void addArmy(Army* const army);
    void removeArmy(unsigned int army);

private:
    QVector<Army*> armies;
};

#endif // DATASAVE_H
