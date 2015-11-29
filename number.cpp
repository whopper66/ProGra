#include "number.h"

Number::Number() :
    value(0),
    selected(false) {

    position = QVector2D(0.5f, 0.5f);
}

Number::Number(int value, QVector2D position) {
    this->value = value;
    this->position = position;
}

int Number::getValue() const {
    return value;
}

bool Number::isSelected() const {
    return selected;
}

QVector2D Number::getPosition() const {
    return position;
}
