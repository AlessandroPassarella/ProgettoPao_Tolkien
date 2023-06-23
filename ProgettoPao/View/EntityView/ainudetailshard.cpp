#include "ainudetailshard.h"
#include "qcombobox.h"

AinuDetailShard::AinuDetailShard(Ainu* a, QWidget *parent):
    EntityDetailShard(a, parent)
{
    QHBoxLayout* ainuLayout = new QHBoxLayout;
    QLabel* levelLabel = new QLabel("Level : ");
    QComboBox* levelMenu = new QComboBox();
    QStringList stringListLevel;
    stringListLevel.append("higher");
    stringListLevel.append("lower");
    levelMenu->addItems(stringListLevel);
    levelMenu->setCurrentIndex(a->getLevel());
    ainuLayout->addWidget(levelLabel);
    ainuLayout->addWidget(levelMenu);

    entityDetailLayout->addLayout(ainuLayout);

    connect(levelMenu, &QComboBox::activated, this, [a](int i){
        a->setLevel(static_cast<Ainu::Level>(i));
    });
}
