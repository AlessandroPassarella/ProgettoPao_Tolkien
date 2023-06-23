#ifndef ENTITYDETAILSHARD_H
#define ENTITYDETAILSHARD_H

#include <QObject>
#include <QWidget>
#include "Model/races.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include <QObject>
#include <QWidget>

class EntityDetailShard : public QWidget
{
    Q_OBJECT
public:
protected:
    explicit EntityDetailShard(Entity* e, QWidget *parent = nullptr);
    Entity* entity;
    QVBoxLayout *entityDetailLayout;
    QLabel* raceLayout;
signals:
    void reloadViews();
};

#endif // ENTITYDETAILSHARD_H
