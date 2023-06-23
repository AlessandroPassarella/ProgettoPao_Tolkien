#include "entitydetailshard.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qspinbox.h"

EntityDetailShard::EntityDetailShard(Entity* e, QWidget *parent)
    : QWidget(parent), entity(e)
{

    entityDetailLayout = new QVBoxLayout;
    setLayout(entityDetailLayout);
    //entityDetailLayout->setSizeConstraint(QLayout::SetFixedSize);

    QHBoxLayout *titleLayout = new QHBoxLayout();

    QLabel* title = new QLabel(QString::fromStdString("<h2>" + entity->getName() + "</h2>"), this);
    titleLayout->addWidget(title, 0, Qt::AlignCenter);
    entityDetailLayout->addLayout(titleLayout);

    //
    raceLayout = new QLabel("");
    entityDetailLayout->addWidget(raceLayout);

    //
    QHBoxLayout* nameLayout = new QHBoxLayout;
    QLabel* name = new QLabel("Name : ");
    QLineEdit* insertName = new QLineEdit(QString::fromStdString(entity->getName()), this);
    nameLayout->addWidget(name);
    nameLayout->addWidget(insertName);
    entityDetailLayout->addLayout(nameLayout);

    //
    QHBoxLayout* ageLayout = new QHBoxLayout;
    QLabel* age = new QLabel("Age : ");
    //age->setFixedSize(50, 100);
    QSpinBox* ageSpinBox = new QSpinBox;
    ageSpinBox->setMinimum(0);
    ageSpinBox->setMaximum(10000);
    ageLayout->addWidget(age);
    ageLayout->addWidget(ageSpinBox);
    entityDetailLayout->addLayout(ageLayout);

    //
    QHBoxLayout* powerLayout = new QHBoxLayout;
    QLabel* power = new QLabel("Power : ");
    QSpinBox* powerSpinBox = new QSpinBox;
    powerSpinBox->setMinimum(0);
    powerSpinBox->setMaximum(10000);
    powerLayout->addWidget(power);
    powerLayout->addWidget(powerSpinBox);
    entityDetailLayout->addLayout(powerLayout);

}
