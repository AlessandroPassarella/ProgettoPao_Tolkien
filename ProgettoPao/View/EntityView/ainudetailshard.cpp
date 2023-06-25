#include "ainudetailshard.h"
#include <QComboBox>
#include <QProgressBar>

AinuDetailShard::AinuDetailShard(Ainu* a, QWidget *parent):
    EntityDetailShard(a, parent)
{
    QHBoxLayout* ainuLayout1 = new QHBoxLayout;
    QLabel* levelLabel = new QLabel("Level : ");
    QComboBox* levelMenu = new QComboBox();
    QStringList stringListLevel;
    stringListLevel.append("higher");
    stringListLevel.append("lower");
    levelMenu->addItems(stringListLevel);
    levelMenu->setCurrentIndex(a->getLevel());
    ainuLayout1->addWidget(levelLabel);
    ainuLayout1->addWidget(levelMenu);

    entityDetailLayout->addLayout(ainuLayout1);

    QHBoxLayout* ainuLayout2 = new QHBoxLayout;
    QLabel* evilLabel = new QLabel("Evilness : ");
    QProgressBar* evilBar = new QProgressBar;
    evilBar->setTextVisible(false);
    evilBar->setRange(0,100);
    evilBar->setValue(min(100, a->evilness()));
    ainuLayout2->addWidget(evilLabel);
    ainuLayout2->addWidget(evilBar);

    entityDetailLayout->addLayout(ainuLayout2);

    connect(levelMenu, &QComboBox::activated, this, [a](int i){
        a->setLevel(static_cast<Ainu::Level>(i));
    });
}
