#ifndef ARMIESVIEW_H
#define ARMIESVIEW_H

#include "Components/basetopbar.h"
#include "viewinterface.h"
//#include "Model/army.h"      //per metodo reload
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>

class Controller;

class ArmiesView : public ViewInterface
{
    Q_OBJECT

public:
    explicit ArmiesView(Controller* controller, const QString& title = "Armies",
                            const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    void reload() override;

    void setHederStrings(const QStringList& headerStrings);

    QString title() const;
    void setTitle(const QString& title);

private:
    Controller* _controller;
    BaseTopBar* _topBar;
    QTableWidget* _table;
    QPushButton* _addButton;
    QPushButton* _deleteButton;

    void setupTable(const QStringList& headerStrings);
    void setupButton();
    void setupLayout();

signals:
    void addArmyButtonClicked();
    void deleteArmyButtonClicked(unsigned row);
};

#endif // ARMIESVIEW_H
