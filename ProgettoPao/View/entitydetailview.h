#ifndef ENTITYDETAILVIEW_H
#define ENTITYDETAILVIEW_H

#include "Controller/entitiescontroller.h"
#include "View/EntityView/entitydetailshard.h"
#include "qboxlayout.h"
#include <QObject>
#include <QWidget>

class EntityDetailView : public QWidget
{
    Q_OBJECT
private:
    EntitiesController* entitiesController;

    QVBoxLayout* shardLayout;
    EntityDetailShard* shard;

    int army;
    int entity;

public:
    explicit EntityDetailView(EntitiesController* entitiesController, QWidget *parent = nullptr);

signals:
    void deletedEntity(int army);

public slots:
    void load(int army, int entity);

};

#endif // ENTITYDETAILVIEW_H
