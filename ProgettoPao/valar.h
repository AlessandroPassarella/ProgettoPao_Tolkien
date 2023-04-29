#ifndef VALAR_H
#define VALAR_H

#include "ainur.h"

class Valar : public Ainur{
public:
    enum Element {aria, acqua, terra, fuoco, morte};

    Valar();
    Valar(string name, int power, bool state, int age, Level level, Element element);

    // Metodi virtuali

    // Metodi get
    Element getElement() const;

    // Metodi set
    void setElement(Element element);

private:
    Element element;
};

#endif // VALAR_H
