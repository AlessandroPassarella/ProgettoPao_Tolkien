#ifndef MODEL_H
#define MODEL_H

#include <qontainer.h>
#include <Model/army.h>
#include <QVector>

using std::vector;

class Model
{
public:
    Model();

    void open(QString filename);
    void save(QString filename) const;

    QVector<Army*> getArmies() const;
    Army* getArmy(unsigned int idx) const;

    void addArmy(Army* const army);
    void removeArmy(unsigned int army);

private:
    QVector<Army*> armies;
};

#endif // MODEL_H
