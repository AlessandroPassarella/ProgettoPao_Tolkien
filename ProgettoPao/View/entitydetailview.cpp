#include "Controller/entitiescontroller.h"
#include "entitydetailview.h"
#include <QPushbutton>
#include <QInputDialog>
#include <QBoxLayout>
#include <QComboBox>
#include <QLabel>

EntityDetailView::EntityDetailView(EntitiesController* entitiesController, QWidget *parent)
    : QWidget(parent), entitiesController(entitiesController)
{
    QVBoxLayout *entityDetailLayout = new QVBoxLayout;
    setLayout(entityDetailLayout);

    QHBoxLayout *titleLayout = new QHBoxLayout;
    title = new QLabel("<h2>Name entity</h2>");
    titleLayout->addWidget(title, 0, Qt::AlignCenter);
    entityDetailLayout->addLayout(titleLayout);

    QLabel* l = new QLabel("cellofatta zioooooooooooooooooooooooooooooooooooo");
    entityDetailLayout->addWidget(l);

    QLabel* race = new QLabel("race : ");
    entityDetailLayout->addWidget(race);

    QComboBox* comboBox = new QComboBox();
    QStringList stringList;
    stringList.append("ciao1");
    stringList.append("ciao2");
    stringList.append("ciao3");
    comboBox->addItems(stringList);
    entityDetailLayout->addWidget(comboBox);



    QLabel* name = new QLabel("name : ");
    entityDetailLayout->addWidget(name);

    QLabel* power = new QLabel("power : ");
    entityDetailLayout->addWidget(power);

    QLabel* age = new QLabel("age : ");
    entityDetailLayout->addWidget(age);

    QLabel* e = new QLabel("dettaglio : ");
    entityDetailLayout->addWidget(e);

    QHBoxLayout *buttonBar = new QHBoxLayout;
    QPushButton *DeleteSoldierBtn = new QPushButton("Delete Soldier");
    buttonBar->addWidget(DeleteSoldierBtn);
    entityDetailLayout->addLayout(buttonBar);

}

void EntityDetailView::load(Entity* entity){
    this->entity = entity;
    title->setText(QString::fromStdString("<h2>" + entity->getName() + "</h2>"));

}
