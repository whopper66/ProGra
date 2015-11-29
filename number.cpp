#include "number.h"

Number::Number() {
    value = 0;
    position = QVector2D(0.5f, 0.5f);
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
