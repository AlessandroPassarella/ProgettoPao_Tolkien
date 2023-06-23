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
    orcLayout->addWidget(kindLabel);
    orcLayout->addWidget(kindMenu);

    entityDetailLayout->addLayout(orcLayout);
}
