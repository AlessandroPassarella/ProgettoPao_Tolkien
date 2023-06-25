#ifndef NAMELINEEDIT_H
#define NAMELINEEDIT_H

#include <QLineEdit>
#include <QObject>
#include <QWidget>

class NameLineEdit : public QLineEdit
{
private:
    QString initialText;
public:
    NameLineEdit(QString text, QWidget* parent = nullptr);
protected:
    virtual void focusOutEvent(QFocusEvent *e) override;
};

#endif // NAMELINEEDIT_H
