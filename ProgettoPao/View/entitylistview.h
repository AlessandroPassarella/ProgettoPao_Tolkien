#ifndef ENTITYLISTVIEW_H
#define ENTITYLISTVIEW_H

#include "Controller/entitiescontroller.h"
#include "qontainer.h"
#include <QTableWidget>
#include <QObject>
#include <QWidget>

class EntityListView : public QWidget{
    Q_OBJECT

private:
    QTableWidget* entitiesTable;

public:
    EntityListView(QWidget *parent = nullptr);
    void load(const Qontainer& entities);

};

#endif // ENTITYLISTVIEW_H
