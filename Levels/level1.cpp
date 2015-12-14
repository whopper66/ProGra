#include "Levels/level1.h"

Level1::Level1() : Level() {
    Initialize();
}

void Level1::Initialize() {
    queue.push_back(Number(10, QPointF(0.3f, 0.3f)));
    queue.push_back(Number(17, QPointF(0.3f, 0.5f)));
    queue.push_back(Number(15, QPointF(0.3f, 0.7f)));
    queue.push_back(Number(12, QPointF(0.5f, 0.3f)));
    queue.push_back(Number(12, QPointF(0.5f, 0.5f)));
    queue.push_back(Number(14, QPointF(0.5f, 0.7f)));
    queue.push_back(Number(16, QPointF(0.7f, 0.3f)));
    queue.push_back(Number(19, QPointF(0.7f, 0.5f)));
    queue.push_back(Number(20, QPointF(0.7f, 0.7f)));
}

Number Level1::nextNumber() {
    Number next = queue.back();
    queue.pop_back();
    return next;
}

int Level1::timeTillNextNumber() {
    /* -1 for infinity */
    if (queue.empty()) {
        return -1;
    }

    return 250;
}

int Level1::getLevelNumber() const {
    return 1;
}
