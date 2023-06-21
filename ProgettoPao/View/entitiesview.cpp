#include "entitiesview.h"
#include "qontainer.h"
#include <QLabel>

EntitiesView::EntitiesView(QWidget *parent, EntitiesController* controller):
    QWidget(parent), entitiesController(controller) {

    QVBoxLayout *entitiesLayout = new QVBoxLayout(this);
    QLabel* l = new QLabel("cellofatta zio");
    entitiesLayout->addWidget(l);
}

void EntitiesView::load(const Army* army) {
    Qontainer entities = army->getEntities();
    //da fare
}
