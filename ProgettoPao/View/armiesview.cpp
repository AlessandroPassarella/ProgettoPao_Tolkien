
#include "armiesview.h"
#include "qlineedit.h"
#include <QHBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QInputDialog>
#include <QDir>
#include <QWidget>

ArmiesView::ArmiesView(QWidget *parent, ArmiesController *armiesController)
    : QWidget(parent), armiesController(armiesController) {
  QVBoxLayout *armiesLayout = new QVBoxLayout(this);
  armiesTable = new QTableWidget(parent);
  armiesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
  armiesTable->setSelectionMode(QAbstractItemView::SingleSelection);
  armiesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  armiesTable->horizontalHeader()->hide();
  armiesTable->verticalHeader()->hide();
  armiesTable->setColumnCount(2);

  QHBoxLayout *buttonBar = new QHBoxLayout;
  QPushButton *addArmyBtn = new QPushButton("+");
  QPushButton *delArmyBtn = new QPushButton("-");
  buttonBar->addWidget(addArmyBtn);
  buttonBar->addWidget(delArmyBtn);

  connect(delArmyBtn, &QPushButton::clicked, [this]() {
    int index = 2 * armiesTable->currentRow() + armiesTable->currentColumn();
    if (index >=0 && index < this->armiesController->getArmies().size())
      this->armiesController->deleteArmy(index);
    load();
  });

  connect(addArmyBtn, &QPushButton::clicked, [this,parent]() {
      bool ok;
      QString text = QInputDialog::getText(parent, "Nuova armata",
            "Nome:", QLineEdit::Normal, "", &ok);
      if (!ok) return;
      this->armiesController->addArmy(text);
      load();
  });

  armiesLayout->addWidget(armiesTable);
  armiesLayout->addLayout(buttonBar);

  load();
}

void ArmiesView::load() {
  QVector<Army *> armies = armiesController->getArmies();
  armiesTable->setRowCount(0);
  armiesTable->setRowCount((armies.size() + 1) / 2);
  for (unsigned i = 0; i < armies.size(); i++)
    armiesTable->setItem(
        i / 2, i % 2,
        new QTableWidgetItem(QString::fromStdString(armies[i]->getName())));
}
