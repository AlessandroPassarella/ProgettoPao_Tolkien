#include <QPushButton>
#include <QLabel>
#include "entitiesview.h"
#include "mainwindow.h"

EntitiesView::EntitiesView(QWidget *parent, EntitiesController* controller):
    QWidget(parent), entitiesController(controller) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout *titleLayout = new QHBoxLayout;
    title = new QLabel;
    titleLayout->addWidget(title, 0, Qt::AlignCenter);
    mainLayout->addLayout(titleLayout);

    QHBoxLayout* lowerLayout = new QHBoxLayout;

    listView = new EntityListView(entitiesController, this);
    lowerLayout->addWidget(listView);

    detailView = new EntityDetailView(entitiesController, this);
    lowerLayout->addWidget(detailView);

    mainLayout->addLayout(lowerLayout);

    QHBoxLayout *labelLayout = new QHBoxLayout;
    QPushButton *backBtn = new QPushButton("< All Armies");
    labelLayout->addWidget(backBtn);
    connect(backBtn, &QPushButton::clicked,  [this, parent](){
        dynamic_cast<MainWindow*>(parent)->openArmiesView();
    });
    mainLayout->addLayout(labelLayout);

}

void EntitiesView::load(int army) {
    title->setText("<h1>" + entitiesController->getName(army) + "</h1>");
    listView->load(army);
}
