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
    QHBoxLayout *newEntityLayout = new QHBoxLayout;

    QLabel* newSoldier = new QLabel("Add new soldier : ");

    QComboBox* comboBox = new QComboBox();
    QStringList stringList;

    stringList.append("Elf");
    stringList.append("Hobbit");
    stringList.append("Dwarf");
    stringList.append("Orc");
    stringList.append("Human");
    stringList.append("Vala");
    stringList.append("Maia");

    comboBox->addItem("");
    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [comboBox](int index){
        if(index == 0) {
            comboBox->setCurrentIndex(-1);
        }
    });
    comboBox->addItems(stringList);

    comboBox->setCurrentIndex(-1);
    entityListLayout->addWidget(comboBox);

    connect(comboBox, &QComboBox::activated, this, [this, parent, comboBox](int i){
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
            comboBox->setCurrentIndex(-1);
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
        qDebug() << entitiesTable;
        qDebug() << this->selectedItems[entitiesTable->currentRow()].index;
        qDebug() << QString::fromStdString(this->selectedItems[entitiesTable->currentRow()].e->getName());
    });

    entityListLayout->addWidget(entitiesTable);
}

void EntityListView::load(int army) {
    this->army = army;
    selectedItems = entitiesController->getEntities(army).search([this](const Entity* e) {
        return QString::fromStdString(e->getName()).contains(searchByName->text(), Qt::CaseInsensitive);
    });
    entitiesTable->setRowCount(selectedItems.size());
    for(unsigned i = 0; i < selectedItems.size(); i++) {
        entitiesTable->setItem( i, 1, new QTableWidgetItem(QString::fromStdString(selectedItems[i].e->getName())));
        entitiesTable->setItem( i, 2, new QTableWidgetItem(QString::number(selectedItems[i].e->getPower())));
    }
}
