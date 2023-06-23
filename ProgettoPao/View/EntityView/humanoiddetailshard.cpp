#include "humanoiddetailshard.h"
#include "qcombobox.h"

HumanoidDetailShard::HumanoidDetailShard(Humanoid* e, QWidget *parent):
    EntityDetailShard(e, parent)
{
    QHBoxLayout* humanoidLayout = new QHBoxLayout;
    QLabel* roleLabel = new QLabel("Role : ");
    QComboBox* roleMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("hunter");
    stringListElement.append("knight");
    stringListElement.append("archer");
    stringListElement.append("worrior");
    stringListElement.append("thief");
    stringListElement.append("king");
    stringListElement.append("queen");
    stringListElement.append("assistant");
    roleMenu->addItems(stringListElement);
    humanoidLayout->addWidget(roleLabel);
    humanoidLayout->addWidget(roleMenu);

    entityDetailLayout->addLayout(humanoidLayout);
}
