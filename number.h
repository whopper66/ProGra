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
    QVector2D getPosition() const;

    Number();
    Number(int value, QVector2D position);
};

#endif // NUMBER_H
