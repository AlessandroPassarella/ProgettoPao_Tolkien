#include "maiadetailshard.h"
#include <QComboBox>

MaiaDetailShard::MaiaDetailShard(Maia* v, QWidget *parent):
    AinuDetailShard(v, parent)
{
    raceLayout->setText("<h3>[ MAIA ]<h3>");

    QHBoxLayout* maiaLayout = new QHBoxLayout;
    QLabel* typologyLabel = new QLabel("Typology : ");
    QComboBox* typologyMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("pure");
    stringListElement.append("wizard");
    stringListElement.append("balrog");
    typologyMenu->addItems(stringListElement);
    typologyMenu->setCurrentIndex(v->getTypology());
    maiaLayout->addWidget(typologyLabel);
    maiaLayout->addWidget(typologyMenu);

    entityDetailLayout->addLayout(maiaLayout);

    connect(typologyMenu, &QComboBox::activated, this, [v](int i){
        v->setTypology(static_cast<Maia::Typology>(i));
    });
}
