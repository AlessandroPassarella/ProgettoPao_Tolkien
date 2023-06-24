#ifndef ENTITYDETAILVIEW_H
#define ENTITYDETAILVIEW_H

#include "Controller/entitiescontroller.h"
#include "View/EntityView/entitydetailshard.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QWidget>

class EntityDetailView : public QWidget
{
    Q_OBJECT
private:
    EntitiesController* entitiesController;

    EntityDetailShard* shard;
    QVBoxLayout* shardLayout;
    QPushButton *delSoldierBtn;
    int army;
    int entity;

public:
    explicit EntityDetailView(EntitiesController* entitiesController, QWidget *parent = nullptr);

    void deleteShard();

signals:
    void updatedEntity(int army);

public slots:
    void load(int army, int entity);

};

#endif // ENTITYDETAILVIEW_H
