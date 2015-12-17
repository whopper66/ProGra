#include "Levels/level1.h"

Level1::Level1() : Level() {
    Initialize();
}

void Level1::Initialize() {
    queue.push_back(Number(1, QPointF(0.1f, 0.1f)));
    queue.push_back(Number(2, QPointF(0.2f, 0.2f)));
    queue.push_back(Number(5, QPointF(0.3f, 0.3f)));
    queue.push_back(Number(8, QPointF(0.4f, 0.4f)));
    queue.push_back(Number(16, QPointF(0.5f, 0.5f)));
    queue.push_back(Number(32, QPointF(0.6f, 0.6f)));
    queue.push_back(Number(64, QPointF(0.7f, 0.7f)));
    queue.push_back(Number(128, QPointF(0.8f, 0.8f)));
    queue.push_back(Number(256, QPointF(0.9f, 0.9f)));

}

Number Level1::nextNumber() {
    Number next = queue.back();
    queue.pop_back();
    return next;
}

int Level1::timeTillNextNumber() {
    /* -1 for infinity */
    if (queue.isEmpty()) {
        return -1;
    }

    return 250;
}

int Level1::getLevelNumber() const {
    return 1;
}

bool Level1::completed(int numbersLeft) const {
	return queue.isEmpty() && numbersLeft == 0;
}

bool Level1::isTimed() const {
    return true;
}

int Level1::getTime() const {
    return 10000; //MILISECONDS
}
