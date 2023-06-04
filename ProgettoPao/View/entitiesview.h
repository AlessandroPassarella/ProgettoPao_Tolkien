#ifndef ENTITIESVIEW_H
#define ENTITIESVIEW_H

#include "viewinterface.h"
#include "Model/entity.h"
#include "Components/backtopbar.h"
#include <typeinfo>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

class Controller;

class EntitiesView: public ViewInterface {
    Q_OBJECT

public:
    explicit EntitiesView(Controller* controller, const QString& title = "Entities",
                             const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    void reload() override;

    void setHederStrings(const QStringList& headerStrings);

    QString title() const;
    void setTitle(const QString& title);

private:
    Controller* _controller;
    BackTopBar* _topBar;
    QTableWidget* _table;

    void setupTable(const QStringList& headerStrings);
    void setupLayout();

    const QString getIconPath(const Entity& entity) const;
};

#endif // ENTITIESVIEW_H
