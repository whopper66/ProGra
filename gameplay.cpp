#include "gameplay.h"

Gameplay::Gameplay() {

    reachable = new bool[MAX_SUM];

    currentLevel = new Level();

}

int Gameplay::findCorrectSum() {
    for (int i = sumOfNumbers/2 + 1; ; i++) {
        if (reachable[i]) {
            return i;
        }
    }
}

void Gameplay::addNumber(Number n) {

    numbers.push_back(n);

    for (int i = sumOfNumbers; i >= 0; i--) {
        reachable[i + n.getValue()] = true;
    }

    sumOfNumbers += n.getValue();

    correctSum = findCorrectSum();
}

void Gameplay::initializeNumbers() {
    std::fill(reachable, reachable + MAX_SUM, false);
    sumOfNumbers = 0;

    for (Number n : numbers) {
        addNumber(n);
    }
}

void Gameplay::deleteSelectedNumbers() {

    QVector<Number> new_numbers;
    for (Number n : numbers) {
        if (!n.isSelected()) {
            new_numbers.push_back(n);
        }
    }

    numbers = new_numbers;

    initializeNumbers();
}
