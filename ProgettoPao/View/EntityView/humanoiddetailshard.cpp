#include "humanoiddetailshard.h"
#include <QComboBox>

HumanoidDetailShard::HumanoidDetailShard(Humanoid* h, QWidget *parent):
    EntityDetailShard(h, parent)
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
    roleMenu->setCurrentIndex(h->getRole());
    humanoidLayout->addWidget(roleLabel);
    humanoidLayout->addWidget(roleMenu);

    entityDetailLayout->addLayout(humanoidLayout);

    connect(roleMenu, &QComboBox::activated, this, [h](int i){
            h->setRole(static_cast<Humanoid::Role>(i));

    });
}
