#include "level.h"

Level::Level() {
    Initialize();
}

void Level::Initialize() {
    queue.push_back(Number(10, QVector2D(0.3f, 0.3f)));
}

Number Level::nextNumber() {
    return queue.back();
}
