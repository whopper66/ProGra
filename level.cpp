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

bool Level::completed() {
    return false;
}

Level::~Level() {

}
