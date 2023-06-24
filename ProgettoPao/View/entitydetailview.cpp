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
#include <QPushButton>
#include <QInputDialog>
#include <QBoxLayout>
#include <QComboBox>
#include <QLabel>

EntityDetailView::EntityDetailView(EntitiesController* entitiesController, QWidget *parent)
    : QWidget(parent), entitiesController(entitiesController), shard(nullptr)
{
    QVBoxLayout *entityDetailLayout = new QVBoxLayout(this);

    shardLayout = new QVBoxLayout;
    entityDetailLayout->addLayout(shardLayout);

    //DELETE
    QHBoxLayout *buttonBar = new QHBoxLayout;
    delSoldierBtn = new QPushButton("Delete Soldier");
    buttonBar->addWidget(delSoldierBtn);
    entityDetailLayout->addLayout(buttonBar);


    delSoldierBtn->hide();

    connect(delSoldierBtn, &QPushButton::clicked, this, [this](){
        this->entitiesController->deleteEntity(army, entity);
        emit updatedEntity(army);
        if(shard) {
            delete shard;
            shard = nullptr;
        }
        delSoldierBtn->hide();

    });

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

    if(shard) {
        shardLayout->addWidget(shard);
        delSoldierBtn->show();
    }

    connect(shard, &EntityDetailShard::reloadViews, this, [this](bool i){
        if(i){
            emit updatedEntity(this->army);
            this->load(this->army, this->entity);
        }else
            emit updatedEntity(this->army);
    });
}

