#include "level3.h"

Level3::Level3() : Level() {
    Initialize();
}

void Level3::Initialize() {
    for (qreal i = 0.1f; i <= 0.95f; i += 0.1f) {
        for (qreal j = 0.1f; j <= 0.95f; j += 0.1f) {
            queue.push_back(Number(10*(i+j), QPointF(i, j)));
        }
    }
}

Number Level3::nextNumber() {
    Number next = queue.back();
    queue.pop_back();
    return next;
}

int Level3::timeTillNextNumber() {
    /* -1 for infinity */
    if (queue.isEmpty()) {
        return -1;
    }

	if(queue.size()%9 || queue.size() == 81)
		return 100;
	else
		return 10000;
}

int Level3::getLevelNumber() const {
    return 3;
}

bool Level3::completed(int numbersLeft) const {
	return queue.isEmpty() && numbersLeft == 0;
}

bool Level3::isTimed() const {
    return true;
}

int Level3::getTime() const {
	return 120000; //MILISECONDS
}
