#include "namelineedit.h"

NameLineEdit::NameLineEdit(QString text, QWidget *parent) :
    QLineEdit(text, parent)
{

}

void NameLineEdit::focusOutEvent(QFocusEvent *e) {
 //non voglio succeda nulla
}
