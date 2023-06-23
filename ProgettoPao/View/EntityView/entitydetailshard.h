#ifndef ENTITYDETAILSHARD_H
#define ENTITYDETAILSHARD_H

#include <QObject>
#include <QWidget>
#include "Model/races.h"
#include "qboxlayout.h"
#include "qlabel.h"

class EntityDetailShard : public QWidget
{
    Q_OBJECT
public:
    explicit EntityDetailShard(Entity* e, QWidget *parent = nullptr);
protected:
    Entity* entity;
    QVBoxLayout *entityDetailLayout;
    QLabel* raceLayout;
signals:

};

#endif // ENTITYDETAILSHARD_H
