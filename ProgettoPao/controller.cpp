#include "controller.h"
#include <typeinfo>
#include <algorithm>

Controller::Controller(Model* model, QObject* parent): QObject(parent),
    _view(nullptr), _model(model) {}

void Controller::setView(View *view) {
    _view = view;

    connect(_view->getArmiesView(), SIGNAL(rowClicked(int)), this, SLOT(goToVehiclesView(int)));
    connect(_view->getArmiesView(), SIGNAL(deleteCityButtonClicked(unsigned)), this, SLOT(deleteCity(unsigned)));
    connect(_view->getEntitiesView(), SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_view->getEntitiesView(), SIGNAL(rowClicked(int)), this, SLOT(goToVehicleDetailView(int)));
    connect(_view->getEntitiesView(), SIGNAL(sort(bool)), this, SLOT(sortVeiclesByState(bool)));
    //connect(_view->getVehicleDetailView(), SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    //connect(_view->getVehicleDetailView(), SIGNAL(maintenanceChanged(int)), this, SLOT(toggleMaintenance(int)));
    //connect(_view->getVehicleDetailView(), SIGNAL(removeButtonClicked()), this, SLOT(removeVehicle()));
    //connect(_view->getVehicleDetailView(), SIGNAL(createMoveDialog()), this, SLOT(createMoveModal()));
    //connect(view->getVehicleDetailView(), SIGNAL(vehicleMove(int)), this, SLOT(saveChage(int)));
}

QVector<Army*> Controller::getArmies() const {
    return _model->getArmies();
}

Qontainer Controller::getEntities() const {
    return _model->getArmy(_currentArmyIndex)->getEntities();
}

Entity* Controller::getEntity() const {
    return _model->getArmy(_currentArmyIndex)->getEntity(_currentEntityIndex);
}

QString Controller::getCurrentArmy() const {
    QString title = _view->getEntitiesView()->title();
    return title.split(QLatin1Char(' ')).last().split(QLatin1Char('<')).first();
}

//QString Controller::getCurrentEntity() const {
//    QString title = _view->getVehicleDetailView()->title();
//    return title.split(QLatin1Char(' ')).last().split(QLatin1Char('<')).first();
//}

void Controller::addArmy(const std::string& name) {
    _model->addArmy(new Army(name));
    dynamic_cast<ViewInterface*>(_view->currentWidget())->reload();
}

void Controller::addEntity(unsigned int army, Entity* const entity) {
    _model->getArmy(army)->addEntity(entity);
    dynamic_cast<ViewInterface*>(_view->currentWidget())->reload();
}

//bool Controller::searchArmy(const std::string& name) const {
//    return _model->searchArmy(name);
//}

//bool Controller::searchEntity(unsigned int amry, const std::string& entity) const {
//    return _model->searchEntity(amry, entity);
//}

//void Controller::sortVeiclesByState(bool ascending) const {
//    _model->sortVehicleByState(_currentCityIndex, ascending);
//}

void Controller::showMessage(const QString& msg) const {
    _view->showMessage(msg);
}

void Controller::goToEntitiesView(int row) {
    EntitiesView* entities = _view->getEntitiesView();
    _currentArmyIndex = row;

    entities->setTitle("Armata di " + QString::fromStdString(_model->getArmy(row)->getName()));
    entities->setHederStrings({ "Tipologia", "Targa", "Stato", "Serve assistenza", "In riserva", "Autonomia", "Fattore green", "Fattore utilizzo" });
    entities->reload();
    _view->setCurrentWidget(entities);
}

//void Controller::goToVehicleDetailView(int row) {
//    VehicleDetailView* vehicleDetail = _view->getVehicleDetailView();
//    _currentVehicleIndex = row;

//    vehicleDetail->setTitle("Veicolo " + QString::fromStdString(_model->getVehicle(_currentCityIndex, row)->targa()));
//    vehicleDetail->reload();
//    _view->setCurrentWidget(vehicleDetail);
//}

void Controller::goBack() const {
    int currentView = _view->currentIndex();    
    _view->setCurrentIndex(currentView - 1);

    if (ArmiesView* view = dynamic_cast<ArmiesView*>(_view->currentWidget()))
        view->reload();
}

//void Controller::toggleMaintenance(int state) const {
//    Veicolo* vehicle = _model->getVehicle(_currentCityIndex, _currentVehicleIndex);

//    if (state == Qt::Checked)
//        vehicle->setStatoAttuale(Veicolo::manutenzione);
//    else if (state == Qt::Unchecked)
//        vehicle->setStatoAttuale(Veicolo::libero);

//    dynamic_cast<ViewInterface*>(_view->widget(_view->currentIndex()))->reload();
//    dynamic_cast<ViewInterface*>(_view->widget(_view->currentIndex() - 1))->reload();
//}

//void Controller::createMoveModal() const {
//    std::string city = getCurrentAtmy().toStdString();
//    _view->getVehicleDetailView()->createMoveDialog(city);
//}

void Controller::removeEntity() const {
    _model->getArmy(_currentArmyIndex)->deleteEntity(_currentEntityIndex);
    _view->getEntitiesView()->reload();
}

//void Controller::saveChage(int row) const {
//    try {
//        Entity* entity = _model->getArmy(_currentArmyIndex)->getEntity(_currentEntityIndex);
//        _model->moveEntity(_currentArmyIndex, row, _currentEntityIndex);
//        dynamic_cast<ViewInterface*>(_view->widget(_view->currentIndex() - 1))->reload();
//        goBack();
//    } catch (std::exception* e) {
//        _view->showMessage(e->what());
//    }
//}

void Controller::deleteArmy(unsigned index) const {
    _model->removeArmy(index);
    ArmiesView* cities = _view->getArmiesView();
    cities->reload();
}
