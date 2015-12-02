#include "number.h"

Number::Number() :
    value(0),
    selected(false) {

    position = QPointF(0.5f, 0.5f);
}

Number::Number(int value, QPointF position) {
    this->value = value;
    this->position = position;
}

int Number::getValue() const {
    return value;
}

bool Number::isSelected() const {
    return selected;
}

QPointF Number::getPosition() const {
    return position;
}
