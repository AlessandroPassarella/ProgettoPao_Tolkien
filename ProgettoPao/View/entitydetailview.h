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

    int army;
    int entity;

public:
    explicit EntityDetailView(EntitiesController* entitiesController, QWidget *parent = nullptr);

public slots:
    void load(int army, int entity);

};

#endif // ENTITYDETAILVIEW_H
