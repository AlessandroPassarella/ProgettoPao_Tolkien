#include <QPushButton>
#include <QLabel>
#include "entitiesview.h"
#include "mainwindow.h"

EntitiesView::EntitiesView(QWidget *parent, EntitiesController* controller):
    QWidget(parent), entitiesController(controller) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout *labelLayout = new QHBoxLayout;
    QPushButton *backBtn = new QPushButton("< All Armies");
    labelLayout->addWidget(backBtn);
    connect(backBtn, &QPushButton::clicked, [this, parent](){
        dynamic_cast<MainWindow*>(parent)->openArmiesView();
    });
    title = new QLabel("<h1></h1>");
    labelLayout->addWidget(title, 0, Qt::AlignCenter);
    mainLayout->addLayout(labelLayout);

    QHBoxLayout* lowerLayout = new QHBoxLayout;

    listView = new EntityListView(this);
    lowerLayout->addWidget(listView);

    detailView = new EntityDetailView(this);
    lowerLayout->addWidget(detailView);

    mainLayout->addLayout(lowerLayout);

}

void EntitiesView::load(int i) {
    title->setText("<h1>" + entitiesController->getName(i) + "</h1>");
    //da fare
}
