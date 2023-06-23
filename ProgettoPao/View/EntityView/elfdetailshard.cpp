#include "elfdetailshard.h"
#include "qcombobox.h"

ElfDetailShard::ElfDetailShard(Elf* e, QWidget *parent):
    HumanoidDetailShard(e, parent)
{
    raceLayout->setText("<h3>[ ELF ]<h3>");

    QHBoxLayout* elfLayout = new QHBoxLayout;
    QLabel* bloolineLabel = new QLabel("Bloodline : ");
    QComboBox* bloodlineMenu = new QComboBox();
    QStringList stringListElement;
    stringListElement.append("vanyar");
    stringListElement.append("noldor");
    stringListElement.append("teleri");
    stringListElement.append("avari");
    bloodlineMenu->addItems(stringListElement);
    bloodlineMenu->setCurrentIndex(e->getBloodline());
    elfLayout->addWidget(bloolineLabel);
    elfLayout->addWidget(bloodlineMenu);

    entityDetailLayout->addLayout(elfLayout);

    connect(bloodlineMenu, &QComboBox::activated, this, [e](int i){
        e->setBloodline(static_cast<Elf::Bloodline>(i));
    });
}
