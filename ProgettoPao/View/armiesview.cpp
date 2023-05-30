#include "armiesview.h"

ArmiesView::ArmiesView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent)
    : ViewInterface(parent), _controller(controller), _topBar(new BaseTopBar(title, parent)), _table(new QTableWidget(parent)),
    _deleteButton(new QPushButton("Elimina armata", parent)) {
    setupTable(headerStrings);
setupButton();

setupLayout();

connect(_topBar, &BaseTopBar::closeSignal, this, &ViewInterface::closeSignal);
connect(_topBar, &BaseTopBar::showAddArmyWizard, this, &ViewInterface::showAddArmyWizard);
connect(_topBar, &BaseTopBar::showAddEntityWizard, this, &ViewInterface::showAddEntityWizard);
connect(_table, &QTableWidget::itemSelectionChanged, this, [this]() {
    _deleteButton->setDisabled(false);
});
connect(_table, &QTableWidget::itemDoubleClicked, this, [=](QTableWidgetItem* item) {
    emit rowClicked(item->row());
    _table->clearSelection();
    _deleteButton->setDisabled(true);
});
connect(_deleteButton, &QPushButton::clicked, this, [this]() {
    if (_table->selectedItems().size() > 0) {
        emit deleteArmyButtonClicked(_table->selectedItems().first()->row());
        _table->clearSelection();
        _deleteButton->setDisabled(true);
    }
});
}

void ArmiesView::reload() {
//    QVector<Army*> armies = _controller->getCities(); //metodo della classe controller
//    _table->setRowCount(armies.size());

//    for (int i = 0; i < _table->rowCount(); i++) {
//        _table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(armies[i]->getName())));
//        _table->setItem(i, 1, new QTableWidgetItem(QString::number(armies[i]->size())));
//    }
}

void ArmiesView::setHederStrings(const QStringList& headerStrings) {
    _table->setColumnCount(headerStrings.size());
    _table->setHorizontalHeaderLabels(headerStrings);
    QHeaderView *header = _table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);
}

QString ArmiesView::title() const {
    return _topBar->title();
}

void ArmiesView::setTitle(const QString &title) {
    _topBar->setTitle(title);
}

void ArmiesView::setupTable(const QStringList& headerStrings) {
    setHederStrings(headerStrings);
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _table->setSelectionBehavior(QAbstractItemView::SelectRows);
    _table->setSelectionMode(QAbstractItemView::SingleSelection);
    _table->setAlternatingRowColors(true);
    _table->verticalHeader()->hide();
}

void ArmiesView::setupButton() {
    _deleteButton->setMaximumWidth(250);
    _deleteButton->setDisabled(true);
}

void ArmiesView::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(_topBar);
    layout->addWidget(_table);
    layout->addWidget(_deleteButton);

    setLayout(layout);
}
