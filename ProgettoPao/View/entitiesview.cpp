#include "entitiesview.h"
#include "Model/vala.h"
#include "Model/maia.h"
#include "Model/dwarf.h"
#include "Model/elf.h"
#include "Model/hobbit.h"
#include "Model/human.h"
#include "./qontainer.h"

EntitiesView::EntitiesView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    ViewInterface(parent), _controller(controller), _topBar(new BackTopBar(title, parent)), _table(new QTableWidget(parent)),
    _addButton(new QPushButton("Aggiungi personaggio", parent)), _deleteButton(new QPushButton("Elimina personaggio", parent)) {
    setupTable(headerStrings);
    setupButton();

    setupLayout();

    connect(_topBar, &BaseTopBar::closeSignal, this, &ViewInterface::closeSignal);
    connect(_topBar, &BaseTopBar::showAddArmyWizard, this, &ViewInterface::showAddArmyWizard);
    connect(_topBar, &BaseTopBar::showAddEntityWizard, this, &ViewInterface::showAddEntityWizard);
    connect(_topBar, &BackTopBar::backButtonClicked, this, [=]() {
        emit backButtonClicked();
        QHeaderView* header = _table->horizontalHeader();
        const QSignalBlocker blocker(header);
        _addButton->setDisabled(true);
        _deleteButton->setDisabled(true);
    });
    connect(_table, &QTableWidget::itemSelectionChanged, this, [this]() {
        _deleteButton->setDisabled(false);
    });
    connect(_addButton, &QPushButton::clicked, this, [this]() {
        emit addEntityButtonClicked();
        _table->clearSelection();
        _addButton->setDisabled(true);
    });
    connect(_deleteButton, &QPushButton::clicked, this, [this]() {
        if (_table->selectedItems().size() > 0) {
            emit deleteEntityButtonClicked(_table->selectedItems().first()->row());
            _table->clearSelection();
            _deleteButton->setDisabled(true);
        }
    });
}

void EntitiesView::reload() {
    Qontainer entities;
    //da fare
}

void EntitiesView::setHederStrings(const QStringList& headerStrings) {
    _table->setColumnCount(headerStrings.size());
    _table->setHorizontalHeaderLabels(headerStrings);
    QHeaderView *header = _table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);
}

QString EntitiesView::title() const {
    return _topBar->title();
}

void EntitiesView::setTitle(const QString &title) {
    _topBar->setTitle(title);
}

void EntitiesView::setupTable(const QStringList& headerStrings) {
    setHederStrings(headerStrings);
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _table->setSelectionBehavior(QAbstractItemView::SelectRows);
    _table->setSelectionMode(QAbstractItemView::SingleSelection);
    _table->setAlternatingRowColors(true);

    _table->verticalHeader()->hide();
}

void EntitiesView::setupButton()
{
    _addButton->setMaximumWidth(250);
    _deleteButton->setMaximumWidth(250);
    _deleteButton->setDisabled(true);
}

void EntitiesView::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(_topBar);
    layout->addWidget(_table);
    layout->addWidget(_addButton);
    layout->addWidget(_deleteButton);

    setLayout(layout);
}

const QString EntitiesView::getIconPath(const Entity& entity) const {
    QString basePath = ":/Extra/Icons/";

    if (typeid(entity) == typeid(Vala))
        return basePath + "vala.png";
    else if (typeid(entity) == typeid(Maia))
        return basePath + "maia.png";
    else if (typeid(entity) == typeid(Dwarf))
        return basePath + "dwarf.png";
    else if (typeid(entity) == typeid(Elf))
        return basePath + "elf.png";
    else if (typeid(entity) == typeid(Hobbit))
        return basePath + "hobbit.png";
    else if (typeid(entity) == typeid(Human))
        return basePath + "human.png";
    else
        return basePath + "orc.png";
}
