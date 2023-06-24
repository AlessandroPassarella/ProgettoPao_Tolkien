#include "entitylistview.h"
#include "Model/races.h"
#include <QLabel>
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
    QHBoxLayout *newEntityLayout = new QHBoxLayout;

    QLabel* newSoldier = new QLabel("Add new soldier : ");

    QComboBox* comboBox = new QComboBox();
    QStringList stringList;

    stringList.append("");
    stringList.append("Elf");
    stringList.append("Hobbit");
    stringList.append("Dwarf");
    stringList.append("Orc");
    stringList.append("Human");
    stringList.append("Vala");
    stringList.append("Maia");

    comboBox->addItems(stringList);

    entityListLayout->addWidget(comboBox);

    connect(comboBox, &QComboBox::activated, this, [this, parent, comboBox](int i){
        bool ok = false;
        QString name = "";
        if (!i)
            return;
        do {
            name = QInputDialog::getText(parent, "New Soldier",
                                         "Nome:", QLineEdit::Normal, "", &ok);
            if (!ok) {
                comboBox->setCurrentIndex(0);
                return;
            }
        } while (name.length() < 3 || name.length() > 14);

        if (ok) {
            Entity* e = nullptr;
            switch (i) {
            case 1:
                e = new Elf(name.toStdString(),0,0, Humanoid::Role::queen, Elf::Bloodline::teleri);
                break;
            case 2:
                e = new Hobbit(name.toStdString(),0,0, Humanoid::Role::hunter, Hobbit::Family::halfing);
                break;
            case 3:
                e = new Dwarf(name.toStdString(),0,0, Humanoid::Role::hunter, Dwarf::Lineage::durin);
                break;
            case 4:
                e = new Orc(name.toStdString(),0,0, Humanoid::Role::queen, Orc::Kind::pure);
                break;
            case 5:
                e = new Human(name.toStdString(),0,0, Humanoid::Role::king, Human::Descent::dunedian);
                break;
            case 6:
                e = new Vala(name.toStdString(),0,0, Ainu::Level::lower, Vala::Element::fire);
                break;
            case 7:
                e = new Maia(name.toStdString(),0,0, Ainu::Level::lower, Maia::Typology::wizard);
                break;
            }
            comboBox->setCurrentIndex(0);
            this->entitiesController->addEntity(army, e);
            load(army);
        }
    });


    newEntityLayout->addWidget(newSoldier);
    newEntityLayout->addWidget(comboBox);
    entityListLayout->addLayout(newEntityLayout);


    //SEARCH BAR
    QHBoxLayout *buttonBar = new QHBoxLayout;
    searchByName = new QLineEdit("", this);
    connect(searchByName, &QLineEdit::textEdited, this, [this](){
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
    connect(entitiesTable, &QTableWidget::cellClicked, this, [this](){
        int entity = this->selectedItems.results[entitiesTable->currentRow()].index;
        emit entityChanged(army, entity);
    });
    entityListLayout->addWidget(entitiesTable);
}

void EntityListView::load(int army) {
    this->army = army;
    entitiesTable->setCurrentItem(nullptr);
    selectedItems = entitiesController->getEntities(army).search([this](const Entity* e) {
        bool classMatches=true;
//        TODO .......
        return classMatches && QString::fromStdString(e->getName()).contains(searchByName->text(), Qt::CaseInsensitive);
    });
    entitiesTable->setRowCount(selectedItems.size);



    for(unsigned i = 0; i < selectedItems.size; i++) {

        QTableWidgetItem *item = new QTableWidgetItem;
        QPixmap* icon = new QPixmap(getIconPath(*(selectedItems.results[i].e)));
        if(icon) std::cout << "puntatore funzionante";
        int h = 10, w = 10;

        item->setData(Qt::DecorationRole, icon->scaled(h ,w)); // NON VAAAAAAA
        if(!icon->scaled(h ,w)) std::cout << "puntatore nullo";

        entitiesTable->setItem( i, 0, item);
        entitiesTable->setItem( i, 1, new QTableWidgetItem(QString::fromStdString(selectedItems.results[i].e->getName())));
        entitiesTable->setItem( i, 2, new QTableWidgetItem(QString::number(selectedItems.results[i].e->getPower())));
    }
}


//void EntityListView::load(int army) {
//    this->army = army;
//    selectedItems = entitiesController->getEntities(army).search([this](const Entity* e) {
//        return QString::fromStdString(e->getName()).contains(searchByName->text(), Qt::CaseInsensitive);
//    });
//    entitiesTable->setRowCount(selectedItems.size);

//    for(unsigned i = 0; i < selectedItems.size; i++) {
//        QTableWidgetItem *item = new QTableWidgetItem;
//        QPixmap* icon = new QPixmap(getIconPath(*(selectedItems.results[i].e)));
//        if(icon) std::cout << "puntatore funzionante";
//        int h = 10, w = 10;

//        item->setData(Qt::DecorationRole, icon->scaled(h ,w)); // NON VAAAAAAA
//        if(!icon->scaled(h ,w)) std::cout << "puntatore nullo";

//        //item->setIcon(icon->scaled(h, w));

//        entitiesTable->setItem( i, 0, item);
//        entitiesTable->setItem( i, 1, new QTableWidgetItem(QString::fromStdString(selectedItems.results[i].e->getName())));
//        entitiesTable->setItem( i, 2, new QTableWidgetItem(QString::number(selectedItems.results[i].e->getPower())));

//        //entitiesTable->setRowHeight(i, 60);
//    }
//    //entitiesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//}

const QString EntityListView::getIconPath(const Entity& entity) const {
    QString basePath = "Icons/";

    if (typeid(entity) == typeid(Elf))
        return basePath + "elf.png";
    else if (typeid(entity) == typeid(Hobbit))
        return basePath + "hobbit.png";
    else if (typeid(entity) == typeid(Dwarf))
        return basePath + "dwarf.png";
    else if (typeid(entity) == typeid(Human))
        return basePath + "human.png";
    else if (typeid(entity) == typeid(Orc))
        return basePath + "orc.png";
    else if (typeid(entity) == typeid(Vala))
        return basePath + "vala.png";
    else
        return basePath + "maia.png";
}
