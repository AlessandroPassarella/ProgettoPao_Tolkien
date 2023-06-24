#include "valadetailshard.h"
#include <QComboBox>

ValaDetailShard::ValaDetailShard(Vala *v, QWidget *parent):
    AinuDetailShard(v, parent)
{
    raceLayout->setText("<h3>[ VALA ]<h3>");

    QHBoxLayout* valaLayout = new QHBoxLayout;
    QLabel* elementLabel = new QLabel("Element : ");
    QComboBox* elementMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("air");
    stringListElement.append("water");
    stringListElement.append("earth");
    stringListElement.append("fire");
    stringListElement.append("death");
    elementMenu->addItems(stringListElement);
    elementMenu->setCurrentIndex(v->getElement());
    valaLayout->addWidget(elementLabel);
    valaLayout->addWidget(elementMenu);

    entityDetailLayout->addLayout(valaLayout);

    connect(elementMenu, &QComboBox::activated, this, [v](int i){
        v->setElement(static_cast<Vala::Element>(i));
    });
}
