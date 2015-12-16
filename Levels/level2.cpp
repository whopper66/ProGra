#include "level2.h"

Level2::Level2() : Level() {
    Initialize();
}

void Level2::Initialize() {
    queue.push_back(Number(11, QPointF(0.15f, 0.91f)));
    queue.push_back(Number(16, QPointF(0.21f, 0.46f)));
    queue.push_back(Number(14, QPointF(0.75f, 0.65f)));
    queue.push_back(Number(12, QPointF(0.12f, 0.3f)));
    queue.push_back(Number(18, QPointF(0.14f, 0.56f)));
    queue.push_back(Number(19, QPointF(0.90f, 0.90f)));
    queue.push_back(Number(15, QPointF(0.20f, 0.20f)));
    queue.push_back(Number(15, QPointF(0.7f, 0.5f)));
    queue.push_back(Number(30, QPointF(0.5f, 0.5f)));
}

Number Level2::nextNumber() {
    Number next = queue.back();
    queue.pop_back();
    return next;
}

int Level2::timeTillNextNumber() {
    /* -1 for infinity */
    if (queue.isEmpty()) {
        return -1;
    }

    return 250;
}

int Level2::getLevelNumber() const {
    return 2;
}

bool Level2::completed(int numbersLeft) const {
    return numbersLeft == 0;
}

bool Level2::isTimed() const {
    return true;
}

int Level2::getTime() const {
    return 80000; //MILISECONDS
}
