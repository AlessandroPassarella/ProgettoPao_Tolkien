#include "entitylistview.h"
#include <QHeaderView>
#include <QTableWidget>
#include <QBoxLayout>
#include <QPushButton>

EntityListView::EntityListView(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *entityListLayout = new QVBoxLayout;
    setLayout(entityListLayout);

    QHBoxLayout *buttonBar = new QHBoxLayout;
    QPushButton *addEntityBtn = new QPushButton("+");
    buttonBar->addWidget(addEntityBtn);
    entityListLayout->addLayout(buttonBar);

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

    entityListLayout->addWidget(entitiesTable);
}

void EntityListView::load(const Qontainer& entities) {
    entitiesTable->setRowCount(entities.size());
    for(unsigned i = 0; i < entities.size(); i++){
        entitiesTable->setItem( i, 1, new QTableWidgetItem(QString::fromStdString(entities[i]->getName())));
        entitiesTable->setItem( i, 2, new QTableWidgetItem(QString::number(entities[i]->getPower())));
    }
}
