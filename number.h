#ifndef NUMBER_H
#define NUMBER_H

#include <QPoint>

class Number {
private:
    int value;
    bool selected;

public:
    int getValue() const;
    bool isSelected() const;

    Number();
};

#endif // NUMBER_H
