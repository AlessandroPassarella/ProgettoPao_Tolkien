#ifndef DATASAVE_H
#define DATASAVE_H

#include <entityvector.h>
#include <Model/army.h>
#include <Model/entity.h>
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
    void clearArmies();

    void addEntity(int army, Entity* entity);

private:
    QVector<Army*> armies;
};

#endif // DATASAVE_H
