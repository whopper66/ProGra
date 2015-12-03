#include "number.h"

Number::Number() :
	Number(0, QPointF(0.5f, 0.5f)) {

}

Number::Number(int value, const QPointF &position) {
	this->value = value;
	this->selected = false;
	this->position = position;
}

int Number::getValue() const {
	return value;
}

bool Number::isSelected() const {
	return selected;
}

const QPointF & Number::getPosition() const {
	return position;
}

void Number::setSelected(bool selected) {
	this->selected = selected;
}

void Number::toggleSelected() {
	selected = !selected;
}
