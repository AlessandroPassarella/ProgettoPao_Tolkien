#ifndef ENTITYDETAILVIEW_H
#define ENTITYDETAILVIEW_H

#include "Controller/entitiescontroller.h"
#include "qlabel.h"
#include <QObject>
#include <QWidget>

class EntityDetailView : public QWidget
{
    Q_OBJECT
private:
    EntitiesController* entitiesController;
    QLabel* title;
    Entity* entity;
public:
    explicit EntityDetailView(EntitiesController* entitiesController, QWidget *parent = nullptr);

    void load(Entity* entity);

};

#endif // ENTITYDETAILVIEW_H
