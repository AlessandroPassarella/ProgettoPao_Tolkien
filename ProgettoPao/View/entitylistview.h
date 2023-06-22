#ifndef ENTITYLISTVIEW_H
#define ENTITYLISTVIEW_H

#include "Controller/entitiescontroller.h"
#include <QTableWidget>
#include <QObject>
#include <QWidget>

class EntityListView : public QWidget{
    Q_OBJECT

private:
    int army;
    QTableWidget* entitiesTable;
    EntitiesController* entitiesController;
    QLineEdit* searchByName;
    Qontainer::SearchResults selectedItems;
public:
    EntityListView(EntitiesController* entitiesController, QWidget *parent = nullptr);
    void load(int army);

};

#endif // ENTITYLISTVIEW_H
