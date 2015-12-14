#include "gameplay.h"

int Gameplay::sumOfSelected() const {
    int ret = 0;
    for (Number n : numbers) {
        if (n.isSelected()) {
            ret += n.getValue();
        }
    }//dupa hehe
    return ret;
}

int Gameplay::findCorrectSum() {
    if (sumOfNumbers == 0) {
        return -1;
    }

    for (int i = sumOfNumbers / 2 + 1; ; i++) {
        if (reachable[i]) {
            return i;
        }
    }
}

void Gameplay::pushNumber(const Number &n, bool pushToVec = true) {
    if (pushToVec) {
        numbers.push_back(n);
    }

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
        pushNumber(n, false);
    }
}

void Gameplay::deleteSelectedNumbers() {
    QVector <Number> new_numbers;
    for (Number n : numbers) {
        if (!n.isSelected()) {
            new_numbers.push_back(n);
        }
    }

    numbers = new_numbers;
    initializeNumbers();
}

void Gameplay::setNextNumberTimer() {
    int interval = currentLevel->timeTillNextNumber();

    if (interval != -1) {
        nextNumberTimer.setSingleShot(true);
        nextNumberTimer.start(interval);
    }
}

void Gameplay::addNumber() {
    pushNumber(currentLevel->nextNumber());
    setNextNumberTimer();
}

void Gameplay::update() {
    /* Ma na celu aktualizowanie stanu gry
     * (np. czy poziom został ukończony).
     * Ew. czy skończył nam się czas. */

    if (sumOfSelected() == correctSum) {
        deleteSelectedNumbers();
    }
}

Gameplay::Gameplay() :
    sumOfNumbers(0),
    correctSum(-1) {

    reachable = new bool[MAX_SUM];
    currentLevel = new Level1();
    numbers = QVector<Number>();

    setNextNumberTimer();
    connect(&nextNumberTimer, SIGNAL(timeout()), this, SLOT(addNumber()));
}

Gameplay::~Gameplay() {
    delete reachable;
    delete currentLevel;
}

int Gameplay::getNumbersCount() const {
	return numbers.size();
}

Number Gameplay::getNthNumber(int n) const {
	return numbers[n];
}

void Gameplay::handleUserClick(const QPointF &pos) {
    for (Number &n : numbers) {
        if ((n.getPosition() - pos).manhattanLength() < 0.1f) {
            /* TODO: ładniejsze wykrywanie kliknięcia
             * w numerek */
            n.toggleSelected();
        }
    }

    update();
}
