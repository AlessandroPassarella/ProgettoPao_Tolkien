#include "Model/army.h"
#include "armiesview.h"
#include "mainwindow.h"
#include <QLineEdit>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QInputDialog>
#include <QDir>
#include <QWidget>
#include <QLabel>

ArmiesView::ArmiesView(QWidget *parent, ArmiesController *armiesController)
    : QWidget(parent), armiesController(armiesController) {

    QVBoxLayout *armiesLayout = new QVBoxLayout(this);

    QHBoxLayout *labelLayout = new QHBoxLayout;
    QLabel *label = new QLabel("<h1>Armies</h1>");
    labelLayout->addWidget(label, 0, Qt::AlignCenter);
    armiesLayout->addLayout(labelLayout);

    armiesTable = new QTableWidget(parent);
    armiesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    armiesTable->setSelectionMode(QAbstractItemView::SingleSelection);
    armiesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    const QStringList& headerStrings = { "Army", "Soldiers" , "Power" };
    armiesTable->setColumnCount(headerStrings.size());
    armiesTable->setHorizontalHeaderLabels(headerStrings);
    armiesTable->setStyleSheet("QHeaderView::section{border-style:solid; font-weight:bold;}");
    armiesTable->verticalHeader()->hide();
    armiesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(armiesTable, &QTableWidget::cellDoubleClicked, this, [this, parent]() {
        if (armiesTable->selectionModel()->hasSelection())
            dynamic_cast<MainWindow *>(parent)->openEntitiesView(
                this->armiesTable->currentRow());
    });

    QHBoxLayout *buttonBar = new QHBoxLayout;
    QPushButton *addArmyBtn = new QPushButton("+");
    QPushButton *delArmyBtn = new QPushButton("-");
    buttonBar->addWidget(addArmyBtn);
    buttonBar->addWidget(delArmyBtn);

    connect(delArmyBtn, &QPushButton::clicked, this, [this]() {
      int index = armiesTable->currentRow();
      if (index >= 0 && index < this->armiesController->getArmies().size())
        this->armiesController->deleteArmy(index);
      load();
    });

    connect(addArmyBtn, &QPushButton::clicked, this, [this, parent]() {
      bool ok = false;
      QString text = "";
      do {
        text = QInputDialog::getText(parent, "Nuova armata",
                                     "Nome:", QLineEdit::Normal, "", &ok);
        if (!ok)
          return;
      } while (text.length() < 3 || text.length() > 14);
      this->armiesController->addArmy(text);
      load();
    });

    armiesLayout->addWidget(armiesTable);
    armiesLayout->addLayout(buttonBar);

}

void ArmiesView::load() {
  QVector<Army *> armies = armiesController->getArmies();
  armiesTable->setRowCount(0);
  armiesTable->setRowCount(armies.size());
  for (unsigned i = 0; i < armies.size(); i++){
    armiesTable->setItem( i, 0, new QTableWidgetItem(QString::fromStdString(armies[i]->getName())));
    armiesTable->setItem( i, 1, new QTableWidgetItem(QString::number(armies[i]->size())));
    armiesTable->setItem( i, 2, new QTableWidgetItem(QString::number(armies[i]->getTotalPower())));
    armiesTable->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    armiesTable->item(i, 1)->setTextAlignment(Qt::AlignCenter);
    armiesTable->item(i, 2)->setTextAlignment(Qt::AlignCenter);
  }
}
