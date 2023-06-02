#include "view.h"
#include "Components/basetopbar.h"
#include "View/armiesview.h"
#include "View/entitiesview.h"

View::View(Controller* controller, QWidget *parent) : QStackedWidget(parent),
    _armiesView(new ArmiesView(controller, "Armata", { "Armata", "Numero entita" })),
    _entitiesView(new EntitiesView(controller)),
    _controller(controller), _titoloApp("CitySharing"), _altezza(1000), _larghezza(700) {

    setFixedSize(_altezza, _larghezza);
    setWindowTitle(_titoloApp);

    addWidget(_armiesView);
    addWidget(_entitiesView);

    setupStyle();

    connect(_armiesView, &ViewInterface::closeSignal, this, &View::close);
    connect(_armiesView, &ViewInterface::showAddArmyWizard, this, [=]() {
        createWizard(true);
    });
    connect(_armiesView, &ViewInterface::showAddEntityWizard, this, [=]() {
        createWizard();
    });

    connect(_entitiesView, &ViewInterface::closeSignal, this, &View::close);
    connect(_entitiesView, &ViewInterface::showAddArmyWizard, this, [=]() {
        createWizard(true);
    });
    connect(_entitiesView, &ViewInterface::showAddEntityWizard, this, [=]() {
        createWizard();
    });

    _armiesView->reload();
}

View::~View() {
    delete _entitiesView;
    delete _armiesView;
}

ArmiesView *View::getArmiesView() const {
    return _armiesView;
}

EntitiesView* View::getEntitiesView() const {
    return _entitiesView;
}

void View::showMessage(const QString &msg) {
    QMessageBox* dialog = new QMessageBox(this);
    dialog->setText(msg);

    dialog->show();
}

void View::setupStyle() {
    QFile file(":/ExtraFiles/Styles/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}

void View::createWizard(bool addArmyMode) {
    //CityWizard* wizard = new CityWizard(addCityMode, _controller, this);
    //wizard->show();
    //wizard->activateWindow();
}
