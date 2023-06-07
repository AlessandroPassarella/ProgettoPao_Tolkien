#ifndef CITIESLISTCONTROLLER_H
#define CITIESLISTCONTROLLER_H

#include "Model/model.h"
#include "view.h"
#include "View/armiesview.h"
#include <QObject>
#include <ostream>
#include <sstream>

class ArmiesView;
class View;

class Controller: public QObject {
    Q_OBJECT

public:
    explicit Controller(Model* model, QObject* parent = nullptr);

    void setView(View* view);

    QVector<Army*> getArmies() const;
    Qontainer getEntities() const;
    Entity* getEntity() const;

    QString getCurrentArmy() const;
    QString getCurrentEntity() const;

    void addArmy(const std::string& name);
    void addEntity(unsigned int army, Entity* const entity);

    bool searchArmy(const std::string& name) const;
    bool searchEntity(unsigned int army, const std::string& entity) const;

    void showMessage(const QString& msg) const;

private:
    View *_view;
    Model* _model;
    unsigned int _currentArmyIndex, _currentEntityIndex;

private slots:
    void goToEntitiesView(int row);
    //void goToVehicleDetailView(int row);
    void goBack() const;
    //void toggleMaintenance(int state) const;
    void createMoveModal() const;
    void removeEntity() const;
    //void saveChage(int row) const;
    void deleteArmy(unsigned index) const;
    //void sortVeiclesByState(bool ascending) const;
};

#endif // CITIESLISTCONTROLLER_H
