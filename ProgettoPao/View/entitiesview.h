#ifndef ENTITIESVIEW_H
#define ENTITIESVIEW_H

#include "Controller/entitiescontroller.h"
#include "Model/army.h"
#include <typeinfo>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>


class EntitiesView: public QWidget {
    Q_OBJECT

public:
    EntitiesView(QWidget *parent, EntitiesController* entitiesController);

    void load(const Army* army);

private:
    EntitiesController* entitiesController;
};

#endif // ENTITIESVIEW_H
