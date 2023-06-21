#ifndef ENTITIESVIEW_H
#define ENTITIESVIEW_H

#include "Model/entity.h"
#include "Components/backtopbar.h"
#include <typeinfo>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

class Controller;

class EntitiesView: public QWidget {
    Q_OBJECT

public:
    EntitiesView(Controller* controller, const QString& title = "Entities",
                             const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    void load();

    void setHederStrings(const QStringList& headerStrings);

    QString title() const;
    void setTitle(const QString& title);

private:
    Controller* _controller;
    BackTopBar* _topBar;
    QTableWidget* _table;
    QPushButton* _addButton;
    QPushButton* _deleteButton;

    void setupTable(const QStringList& headerStrings);
    void setupButton();
    void setupLayout();

    const QString getIconPath(const Entity& entity) const;
signals:
    void addEntityButtonClicked();
    void deleteEntityButtonClicked(unsigned row);
};

#endif // ENTITIESVIEW_H
