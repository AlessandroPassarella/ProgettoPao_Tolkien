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

    listView = new EntityListView(this);
    lowerLayout->addWidget(listView);

    detailView = new EntityDetailView(controller, this);
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

void EntitiesView::load(int i) {
    title->setText("<h1>" + entitiesController->getName(i) + "</h1>");
    listView->load(entitiesController->getEntities(i));
}
