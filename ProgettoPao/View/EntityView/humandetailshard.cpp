#include "humandetailshard.h"
#include <QComboBox>

HumanDetailShard::HumanDetailShard(Human* h, QWidget *parent):
    HumanoidDetailShard(h, parent)
{
    raceLayout->setText("<h3>[ HUMAN ]<h3>");

    QHBoxLayout* humanLayout = new QHBoxLayout;
    QLabel* descentLabel = new QLabel("Descent : ");
    QComboBox* descentMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("dunedian");
    stringListElement.append("medianum");
    stringListElement.append("bard");
    descentMenu->addItems(stringListElement);
    descentMenu->setCurrentIndex(h->getDescent());
    humanLayout->addWidget(descentLabel);
    humanLayout->addWidget(descentMenu);

    entityDetailLayout->addLayout(humanLayout);

    connect(descentMenu, &QComboBox::activated, this, [h](int i){
        h->setDescent(static_cast<Human::Descent>(i));
    });
}
