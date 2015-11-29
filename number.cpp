#include "number.h"

Number::Number() {

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
