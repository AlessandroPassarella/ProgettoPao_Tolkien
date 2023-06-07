#ifndef VIEW_H
#define VIEW_H

#include "Model/model.h"
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

    QString openedFileName;
    Model model;
    //QTableWidget* armiesTable; sarebbe armiesView

    void setupStyle();

    const QString title;
    const unsigned int heigh;
    const unsigned int width;

private slots:
    void createWizard(bool addArmyMode = false);

    void openFile();
    void saveFile();
};

#endif // VIEW_H
