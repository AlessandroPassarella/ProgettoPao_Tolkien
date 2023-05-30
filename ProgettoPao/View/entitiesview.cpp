#include "entitiesview.h"
#include "Model/vala.h"
#include "Model/maia.h"
#include "Model/dwarf.h"
#include "Model/elf.h"
#include "Model/hobbit.h"
#include "Model/human.h"
#include "./qontainer.h"

EntitiesView::EntitiesView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    ViewInterface(parent), _controller(controller), _topBar(new BackTopBar(title, parent)), _table(new QTableWidget(parent)), _order(Qt::SortOrder::AscendingOrder) {
    setupTable(headerStrings);

    setupLayout();

    connect(_topBar, &BaseTopBar::closeSignal, this, &ViewInterface::closeSignal);
    connect(_topBar, &BaseTopBar::showAddArmyWizard, this, &ViewInterface::showAddArmyWizard);
    connect(_topBar, &BaseTopBar::showAddEntityWizard, this, &ViewInterface::showAddEntityWizard);
    connect(_topBar, &BackTopBar::backButtonClicked, this, [=]() {
        emit backButtonClicked();
        _order = Qt::SortOrder::DescendingOrder;
        QHeaderView* header = _table->horizontalHeader();
        const QSignalBlocker blocker(header);
        header->setSortIndicator(2, _order);
    });
    connect(_table, &QTableWidget::itemDoubleClicked, this, [=](QTableWidgetItem* item) {
        emit rowClicked(item->row());
        _table->clearSelection();
    });
    connect(_table->horizontalHeader(), &QHeaderView::sortIndicatorChanged, this, [=](int index, Qt::SortOrder order) {
        if (index != 2) {
            QHeaderView* header = _table->horizontalHeader();
            const QSignalBlocker blocker(header);
            header->setSortIndicator(2, _order);
        } else {
            _order = order;
            _table->sortItems(index, _order);
            emit sort(order == Qt::SortOrder::AscendingOrder);
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
    header->setSortIndicator(2, _order);
    header->setSortIndicatorShown(true);
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

void EntitiesView::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(_topBar);
    layout->addWidget(_table);

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
