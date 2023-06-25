#include "humanoiddetailshard.h"
#include <QComboBox>
#include <QProgressBar>

HumanoidDetailShard::HumanoidDetailShard(Humanoid* h, QWidget *parent):
    EntityDetailShard(h, parent)
{
    QHBoxLayout* humanoidLayout1 = new QHBoxLayout;
    QLabel* roleLabel = new QLabel("Role : ");
    QComboBox* roleMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("hunter");
    stringListElement.append("knight");
    stringListElement.append("archer");
    stringListElement.append("warrior");
    stringListElement.append("thief");
    stringListElement.append("king");
    stringListElement.append("queen");
    stringListElement.append("assistant");
    roleMenu->addItems(stringListElement);
    roleMenu->setCurrentIndex(h->getRole());
    humanoidLayout1->addWidget(roleLabel);
    humanoidLayout1->addWidget(roleMenu);

    entityDetailLayout->addLayout(humanoidLayout1);

    QHBoxLayout* humanoidLayout2 = new QHBoxLayout;
    QLabel* combatPowerLabel = new QLabel("Combat Power : ");
    QProgressBar* combatPowerBar = new QProgressBar;
    combatPowerBar->setTextVisible(false);
    combatPowerBar->setRange(0,100);
    combatPowerBar->setValue(h->combatPower()<100?h->combatPower():100);
    humanoidLayout2->addWidget(combatPowerLabel);
    humanoidLayout2->addWidget(combatPowerBar);

    entityDetailLayout->addLayout(humanoidLayout2);

    connect(roleMenu, &QComboBox::activated, this, [h](int i){
            h->setRole(static_cast<Humanoid::Role>(i));

    });
}
