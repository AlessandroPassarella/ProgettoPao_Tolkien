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

    //
    QLabel* raceLayout = new QLabel("Race : Humanoide_prova");
    entityDetailLayout->addWidget(raceLayout);

    //
    QHBoxLayout* nameLayout = new QHBoxLayout;
    QLabel* name = new QLabel("Name : ");
    QLineEdit* insertName = new QLineEdit("", this);
    nameLayout->addWidget(name);
    nameLayout->addWidget(insertName);
    entityDetailLayout->addLayout(nameLayout);

    //
    QHBoxLayout* ageLayout = new QHBoxLayout;

    entityDetailLayout->addLayout(ageLayout);
    //
    QHBoxLayout* powerLayout = new QHBoxLayout;

    entityDetailLayout->addLayout(powerLayout);

    //
    QHBoxLayout* elementLayout = new QHBoxLayout;
    QLabel* element = new QLabel("Element : ");

    QComboBox* elementMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("air");
    stringListElement.append("water");
    stringListElement.append("earth");
    stringListElement.append("fire");
    stringListElement.append("death");
    elementMenu->addItems(stringListElement);

    elementLayout->addWidget(element);
    elementLayout->addWidget(elementMenu);
    entityDetailLayout->addLayout(elementLayout);

    //
    QHBoxLayout* levelLayout = new QHBoxLayout;
    QLabel* level = new QLabel("Level : ");

    QComboBox* levelMenu = new QComboBox();
    QStringList stringListLevel;
    stringListLevel.append("higher");
    stringListLevel.append("lower");
    levelMenu->addItems(stringListLevel);

    levelLayout->addWidget(level);
    levelLayout->addWidget(levelMenu);
    entityDetailLayout->addLayout(levelLayout);


    //

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
