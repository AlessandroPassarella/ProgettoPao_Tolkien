#include "Controller/entitiescontroller.h"
#include "Model/races.h"
#include "View/EntityView/dwarfdetailshard.h"
#include "View/EntityView/elfdetailshard.h"
#include "View/EntityView/hobbitdetailshard.h"
#include "View/EntityView/humandetailshard.h"
#include "View/EntityView/maiadetailshard.h"
#include "View/EntityView/orcdetailshard.h"
#include "View/EntityView/valadetailshard.h"
#include "entitydetailview.h"
#include <QPushbutton>
#include <QInputDialog>
#include <QBoxLayout>
#include <QComboBox>
#include <QLabel>

EntityDetailView::EntityDetailView(EntitiesController* entitiesController, QWidget *parent)
    : QWidget(parent), entitiesController(entitiesController), shard(nullptr)
{
    QVBoxLayout *entityDetailLayout = new QVBoxLayout;
    setLayout(entityDetailLayout);
    //entityDetailLayout->setSizeConstraint(QLayout::SetFixedSize);

    shardLayout = new QVBoxLayout;
    entityDetailLayout->addLayout(shardLayout);

    //DELETE
    QHBoxLayout *buttonBar = new QHBoxLayout(this);
    QPushButton *delSoldierBtn = new QPushButton("Delete Soldier");
    buttonBar->addWidget(delSoldierBtn);
    entityDetailLayout->addLayout(buttonBar);

    connect(delSoldierBtn, &QPushButton::clicked, this, [this](){
        this->entitiesController->deleteEntity(army, entity);
        emit deletedEntity(army);

        if(shard) {
            delete shard;
            shard = nullptr;
        }

    });

    //connect(shard, &EntityDetailShard::reloadListView, this, &EntityDetailView::load);


}


void EntityDetailView::load(int army, int entity){
    this->army = army;
    this->entity = entity;
    if(shard) {
        delete shard;
        shard = nullptr;
    }
    if(Elf* e = dynamic_cast<Elf*>(entitiesController->getEntity(army, entity)))
        shard = new ElfDetailShard(e, this);
    else if (Human* h = dynamic_cast<Human *>(entitiesController->getEntity(army, entity)))
        shard = new HumanDetailShard(h, this);
    else if (Hobbit* h = dynamic_cast<Hobbit *>(entitiesController->getEntity(army, entity)))
        shard = new HobbitDetailShard(h, this);
    else if (Orc* o = dynamic_cast<Orc *>(entitiesController->getEntity(army, entity)))
        shard = new OrcDetailShard(o, this);
    else if (Dwarf* d = dynamic_cast<Dwarf *>(entitiesController->getEntity(army, entity)))
        shard = new DwarfDetailShard(d, this);
    else if (Vala* v = dynamic_cast<Vala *>(entitiesController->getEntity(army, entity)))
        shard = new ValaDetailShard(v, this);
    else if (Maia* m = dynamic_cast<Maia *>(entitiesController->getEntity(army, entity)))
        shard = new MaiaDetailShard(m, this);


    if(shard)
            shardLayout->addWidget(shard);
//    delete shardLayout->takeAt(0); SERVE ??
}

