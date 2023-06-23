#include "dwarfdetailshard.h"
#include "qcombobox.h"

DwarfDetailShard::DwarfDetailShard(Dwarf *d, QWidget *parent):
    HumanoidDetailShard(d, parent)
{
     raceLayout->setText("<h3>[ DWARF ]<h3>");

    QHBoxLayout* dwarfLayout = new QHBoxLayout;
    QLabel* lineageLabel = new QLabel("Lineage : ");
    QComboBox* lineageMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("durin");
    stringListElement.append("barbafiamma");
    stringListElement.append("nerachiave");
    stringListElement.append("vastifascio");
    stringListElement.append("pugniferro");
    stringListElement.append("pediroccia");
    stringListElement.append("barbadura");
    lineageMenu->addItems(stringListElement);
    dwarfLayout->addWidget(lineageLabel);
    dwarfLayout->addWidget(lineageMenu);

    entityDetailLayout->addLayout(dwarfLayout);
}
