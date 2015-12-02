#include "Levels/level1.h"

Level1::Level1() : Level() {
    Initialize();
}

void Level1::Initialize() {
    queue.push_back(Number(10, QVector2D(0.3f, 0.3f)));
    queue.push_back(Number(30, QVector2D(0.3f, 0.5f)));
    queue.push_back(Number(50, QVector2D(0.7f, 0.5f)));
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
