#include "level.h"

Level::Level() {
	Initialize();
}

void Level::Initialize() {

}

Number Level::nextNumber() {
	return Number();
}

int Level::timeTillNextNumber() {
	return 250;
}

int Level::getLevelNumber() const {
    return 0;
}

bool Level::completed() const {
    return false;
}

bool Level::completed(int numbersLeft) const {
    return false;
}

bool Level::isTimed() const {
    return false;
}

int Level::getTime() const {
    return -1;
}

Level::~Level() {

}
