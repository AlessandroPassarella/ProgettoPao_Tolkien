#ifndef ENTITYDETAILVIEW_H
#define ENTITYDETAILVIEW_H

#include "Controller/entitiescontroller.h"
#include <QObject>
#include <QWidget>

class EntityDetailView : public QWidget
{
    Q_OBJECT
private:
    EntitiesController* entitiesController;
public:
    explicit EntityDetailView(EntitiesController* entitiesController, QWidget *parent = nullptr);

signals:

};

#endif // ENTITYDETAILVIEW_H
