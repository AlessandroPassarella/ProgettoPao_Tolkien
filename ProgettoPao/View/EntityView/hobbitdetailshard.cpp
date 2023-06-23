#include "hobbitdetailshard.h"
#include "qcombobox.h"

HobbitDetailShard::HobbitDetailShard(Hobbit *h, QWidget *parent):
    HumanoidDetailShard(h, parent)
{
    raceLayout->setText("<h3>[ HOBBIT ]<h3>");

    QHBoxLayout* hobbitLayout = new QHBoxLayout;
    QLabel* familyLabel = new QLabel("Family : ");
    QComboBox* familyMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("halfing");
    stringListElement.append("harfoots");
    stringListElement.append("sturoi");
    familyMenu->addItems(stringListElement);
    familyMenu->setCurrentIndex(h->getFamily());
    hobbitLayout->addWidget(familyLabel);
    hobbitLayout->addWidget(familyMenu);

    entityDetailLayout->addLayout(hobbitLayout);

    connect(familyMenu, &QComboBox::activated, this, [h](int i){
        h->setFamily(static_cast<Hobbit::Family>(i));
    });
}
