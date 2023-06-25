#ifndef ENTITYDETAILSHARD_H
#define ENTITYDETAILSHARD_H

#include <QObject>
#include <QWidget>
#include "Model/races.h"
#include <QBoxLayout>
#include <QLabel>
#include <QObject>
#include <QWidget>

class EntityDetailShard : public QWidget
{
    Q_OBJECT
protected:
    explicit EntityDetailShard(Entity* e, QWidget *parent = nullptr);
    Entity* entity;
    QVBoxLayout *entityDetailLayout;
    QLabel* raceLayout;
signals:
    void reloadViews(bool);
};

#define min(a,b) ((b>a)?a:b)

#endif // ENTITYDETAILSHARD_H
