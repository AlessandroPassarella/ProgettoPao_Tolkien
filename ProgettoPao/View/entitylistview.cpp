#include "entitylistview.h"
#include "Model/races.h"
#include "qlabel.h"
#include <QCombobox>
#include <QInputDialog>
#include <QHeaderView>
#include <QTableWidget>
#include <QBoxLayout>
#include <QPushButton>

EntityListView::EntityListView(EntitiesController* entitiesController, QWidget *parent)
    : QWidget(parent), entitiesController(entitiesController)
{

    QVBoxLayout *entityListLayout = new QVBoxLayout;
    setLayout(entityListLayout);



    //COMBO BOX
    //QPushButton *addEntityBtn = new QPushButton("+");
    //buttonBar->addWidget(addEntityBtn);

    QComboBox* comboBox = new QComboBox();
    QStringList stringList;

    stringList.append("Elf");
    stringList.append("Hobbit");
    stringList.append("Dwarf");
    stringList.append("Orc");
    stringList.append("Human");
    stringList.append("Vala");
    stringList.append("Maia");

    comboBox->addItems(stringList);
    //comboBox->setCurrentIndex(2);

    entityListLayout->addWidget(comboBox);

    connect(comboBox, &QComboBox::activated, this, [this, parent](int i){
        bool ok = false;
        QString name = "";
        do {
            name = QInputDialog::getText(parent, "New Soldier",
                                         "Nome:", QLineEdit::Normal, "", &ok);
            if (!ok)
                return;
        } while (name.length() < 3 || name.length() > 14);

        if (ok) {
            Entity* e = nullptr;
            switch (i) {
            case 0:
                e = new Elf(name.toStdString(),0,0, Humanoid::Role::queen, Elf::Bloodline::teleri);
                break;
            case 1:
                e = new Hobbit(name.toStdString(),0,0, Humanoid::Role::hunter, Hobbit::Family::halfing);
                break;
            case 2:
                e = new Dwarf(name.toStdString(),0,0, Humanoid::Role::hunter, Dwarf::Lineage::durin);
                break;
            case 3:
                e = new Orc(name.toStdString(),0,0, Humanoid::Role::queen, Orc::Kind::pure);
                break;
            case 4:
                e = new Human(name.toStdString(),0,0, Humanoid::Role::king, Human::Descent::dunedian);
                break;
            case 5:
                e = new Vala(name.toStdString(),0,0, Ainu::Level::lower, Vala::Element::fire);
                break;
            case 6:
                e = new Maia(name.toStdString(),0,0, Ainu::Level::lower, Maia::Typology::wizard);
                break;
            }
            this->entitiesController->addEntity(army, e);
            load(army);
        }

    });



    //SEARCH BAR
    QHBoxLayout *buttonBar = new QHBoxLayout;
    searchByName = new QLineEdit("", this);
    connect(searchByName, &QLineEdit::returnPressed, this, [this](){
        this->load(this->army);
    });
    buttonBar->addWidget(new QLabel("Search by name:"));
    buttonBar->addWidget(searchByName);

    entityListLayout->addLayout(buttonBar);



    //TABLE ENTITIES
    entitiesTable = new QTableWidget(parent);
    entitiesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    entitiesTable->setSelectionMode(QAbstractItemView::SingleSelection);
    entitiesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    const QStringList& headerStrings = { "" , "Name", "Power" };
    entitiesTable->setColumnCount(headerStrings.size());
    entitiesTable->setHorizontalHeaderLabels(headerStrings);
    entitiesTable->setStyleSheet("QHeaderView::section{border-style:solid; font-weight:bold;}");
    entitiesTable->verticalHeader()->hide();
    entitiesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
//    connect(entitiesTable, &QTableWidget::cellClicked, this, [this](){
//        qDebug() << entitiesTable;
//        qDebug() << entitiesTable->currentRow();
//        qDebug() << QString::fromStdString(this->currentDisplayedEntities.get(entitiesTable->currentRow())->getName());
//    });

    entityListLayout->addWidget(entitiesTable);
}

void EntityListView::load(int army) {
    this->army = army;
    Qontainer currentDisplayedEntities = entitiesController->getEntities(army).search([this](const Entity* e){
        return e->getName().find(this->searchByName->text().toStdString()) != std::string::npos;
    });
    entitiesTable->setRowCount(currentDisplayedEntities.size());
    for(unsigned i = 0; i < currentDisplayedEntities.size(); i++){
        entitiesTable->setItem( i, 1, new QTableWidgetItem(QString::fromStdString(currentDisplayedEntities[i]->getName())));
        entitiesTable->setItem( i, 2, new QTableWidgetItem(QString::number(currentDisplayedEntities[i]->getPower())));
    }
}
