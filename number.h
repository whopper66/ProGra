#ifndef NUMBER_H
#define NUMBER_H

#include <QPoint>
#include <QVector2D>

class Number {
private:
    int value;
    bool selected;

    QVector2D position;
    /* pozycja numeru na ekranie, proponuję współrzędne z zakresu
     * [0..1] + skalowanie w funkcji rysującej */

public:
    int getValue() const;
    bool isSelected() const;

    Number();
};

#endif // NUMBER_H
