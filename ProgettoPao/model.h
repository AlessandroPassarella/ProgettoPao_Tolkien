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
    ~Model();

    QVector<Army*> getArmies() const;
    Army* getArmy(unsigned int idx) const;

    void addArmy(Army* const army);
    void removeArmy(unsigned int army);

    //metodo setArmy per caricare un armata esportata in precedenza

//    void addEntity(unsigned int army, Entity* const entity);
//    Entity* getEntity(unsigned int army, unsigned int entity);
//    Entity* removeEntity(unsigned int army, unsigned int entity);

private:
    QVector<Army*> armies;
};

#endif // MODEL_H
