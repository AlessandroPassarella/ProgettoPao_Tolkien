#include "entitylistview.h"
#include "Model/races.h"
#include <QLabel>
#include <QComboBox>
#include <QInputDialog>
#include <QHeaderView>
#include <QTableWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QCoreApplication>
#include <QFile>

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
    const QStringList& headerStrings = { "Race" , "Name", "Power" };
    entitiesTable->setColumnCount(headerStrings.size());
    entitiesTable->setHorizontalHeaderLabels(headerStrings);
    entitiesTable->setStyleSheet("QHeaderView::section{border-style:solid; font-weight:bold;}");
    entitiesTable->verticalHeader()->hide();
    entitiesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    entitiesTable->setColumnWidth(0, 30);
    entitiesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);

    connect(entitiesTable, &QTableWidget::cellClicked, this, [this](){
        int entity = this->selectedItems.results[entitiesTable->currentRow()].index;
        emit entityChanged(army, entity);
    });
    entityListLayout->addWidget(entitiesTable);
}

const QString getIconPath(const Entity& entity) {
    if (typeid(entity) == typeid(Elf))
        return "elf";
    if (typeid(entity) == typeid(Hobbit))
        return "hobbit";
    if (typeid(entity) == typeid(Dwarf))
        return "dwarf";
    if (typeid(entity) == typeid(Human))
        return "human";
    if (typeid(entity) == typeid(Orc))
        return "orc";
    if (typeid(entity) == typeid(Vala))
        return "vala";
    if (typeid(entity) == typeid(Maia))
        return "maia";
    else
        return "";
}

void EntityListView::load(int army) {
    this->army = army;
    entitiesTable->setCurrentItem(nullptr);
    selectedItems = entitiesController->getEntities(army).search([this](const Entity* e) {
        return QString::fromStdString(e->getName()).contains(searchByName->text(), Qt::CaseInsensitive);
    });
    entitiesTable->setRowCount(selectedItems.size);


    for(unsigned i = 0; i < selectedItems.size; i++) {

      // a color attivare la stringa 'C', in B/W la striga 'BW'
        QString colorSchema = "C";
      //QString colorSchema = "BW";

        QString iconFileName = ":/Extra/icons/" +
                               getIconPath(*selectedItems.results[i].e) +
                               colorSchema + ".png";
        QFile file(iconFileName);
        QIcon icon(iconFileName);
        QTableWidgetItem *itemIcon = new QTableWidgetItem;
        itemIcon->setIcon(icon);

        entitiesTable->setItem(i, 0, itemIcon);

        QTableWidgetItem *itemName = new QTableWidgetItem(QString::fromStdString(
            selectedItems.results[i].e->getName()));
        itemName->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *itemPower = new QTableWidgetItem(QTableWidgetItem(QString::number(
            selectedItems.results[i].e->getPower())));
        itemPower->setTextAlignment(Qt::AlignCenter);

        entitiesTable->setItem(i, 1, itemName);
        entitiesTable->setItem(i, 2, itemPower);
        entitiesTable->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
        entitiesTable->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    }
}

