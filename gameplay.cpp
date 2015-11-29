#include "gameplay.h"

Gameplay::Gameplay() :
    sumOfNumbers(0),
    correctSum(-1) {

    reachable = new bool[MAX_SUM];
    currentLevel = new Level();
    numbers = QVector<Number>();

    addNumber(currentLevel->nextNumber());
}

int Gameplay::findCorrectSum() {
    if (sumOfNumbers == 0) {
        return -1;
    }

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

int Gameplay::getNumbersCount() const {
    return numbers.size();
}

Number Gameplay::getNthNumber(int n) const {
    return numbers[n];
}

Gameplay::~Gameplay() {
    delete reachable;
    delete currentLevel;
}
