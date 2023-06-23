#include "orcdetailshard.h"
#include "qcombobox.h"

OrcDetailShard::OrcDetailShard(Orc *o, QWidget *parent):
    HumanoidDetailShard(o, parent)
{
    raceLayout->setText("<h3>[ ORC ]<h3>");

    QHBoxLayout* orcLayout = new QHBoxLayout;
    QLabel* kindLabel = new QLabel("Kind : ");
    QComboBox* kindMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("pure");
    stringListElement.append("goblin");
    stringListElement.append("white");
    kindMenu->addItems(stringListElement);
    kindMenu->setCurrentIndex(o->getKind());
    orcLayout->addWidget(kindLabel);
    orcLayout->addWidget(kindMenu);

    entityDetailLayout->addLayout(orcLayout);

    connect(kindMenu, &QComboBox::activated, this, [o](int i){
        o->setKind(static_cast<Orc::Kind>(i));
    });
}
