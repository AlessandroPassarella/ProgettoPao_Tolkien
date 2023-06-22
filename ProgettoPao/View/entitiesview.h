#ifndef ENTITIESVIEW_H
#define ENTITIESVIEW_H

#include <QLabel>
#include <typeinfo>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include "Controller/entitiescontroller.h"
#include "View/entitylistview.h"
#include "View/entitydetailview.h"


class EntitiesView: public QWidget {
    Q_OBJECT

    EntityDetailView* detailView;
    EntityListView* listView;

public:
    EntitiesView(QWidget *parent, EntitiesController* entitiesController);
    void load(int army);

private:
    EntitiesController* entitiesController;
    QLabel* title;
};

#endif // ENTITIESVIEW_H
