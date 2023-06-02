#ifndef VIEW_H
#define VIEW_H

#include "View/armiesview.h"
#include "View/entitiesview.h"
#include <QStackedWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFile>

class Controller;
class ArmiesView;
class EntitiesView;

class View : public QStackedWidget {
    Q_OBJECT

public:
    explicit View(Controller* controller, QWidget *parent = nullptr);
    ~View();

    ArmiesView* getArmiesView() const;
    EntitiesView* getEntitiesView() const;

    void showMessage(const QString& msg);

    QWidget* getCurrentView() const;
    void setCurrentView(QWidget* view);

private:
    ArmiesView* _armiesView;
    EntitiesView* _entitiesView;
    Controller* _controller;

    void setupStyle();

    const QString _titoloApp;
    const unsigned int _altezza;
    const unsigned int _larghezza;

private slots:
    void createWizard(bool addArmyMode = false);
};

#endif // VIEW_H
