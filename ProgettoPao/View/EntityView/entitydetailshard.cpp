#include "entitydetailshard.h"
#include "View/entitydetailview.h"
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

    connect(insertName, &QLineEdit::textEdited, this, [this, insertName](){
        this->entity->setName(insertName->text().toStdString());
        //emit reloadListView(dynamic_cast<EntityDetailView *>(this)->army, dynamic_cast<EntityDetailView *>(this)->entity);
    });

    //
    QHBoxLayout* ageLayout = new QHBoxLayout;
    QLabel* age = new QLabel("Age : ");
    QSpinBox* ageSpinBox = new QSpinBox();
    ageSpinBox->setValue(entity->getAge());
    ageSpinBox->setMinimum(0);
    ageSpinBox->setMaximum(200000);
    ageLayout->addWidget(age);
    ageLayout->addWidget(ageSpinBox);
    entityDetailLayout->addLayout(ageLayout);

    connect(ageSpinBox, &QSpinBox::textChanged, this, [this, ageSpinBox](){
        this->entity->setAge(ageSpinBox->value());
    });

    //
    QHBoxLayout* powerLayout = new QHBoxLayout;
    QLabel* power = new QLabel("Power : ");
    QSpinBox* powerSpinBox = new QSpinBox;
    powerSpinBox->setValue(entity->getPower());
    powerSpinBox->setMinimum(0);
    //powerSpinBox->setMaxVisibleItems(200000); // problema da risolvere!! , idem in Age
    powerSpinBox->setMaximum(200000);
    powerLayout->addWidget(power);
    powerLayout->addWidget(powerSpinBox);
    entityDetailLayout->addLayout(powerLayout);

    connect(powerSpinBox, &QSpinBox::textChanged, this, [this, powerSpinBox](){
        this->entity->setPower(powerSpinBox->value());
    });

}
