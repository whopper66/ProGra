#include "gameplay.h"

int Gameplay::sumOfSelected() const {
    int ret = 0;
    for (Number n : numbers) {
        if (n.isSelected()) {
            ret += n.getValue();
        }
    }
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
    for (int i = sumOfNumbers; i >= 0; i--)
        if (reachable[i]) {
            reachable[i + n.getValue()] = true;
    }
    sumOfNumbers += n.getValue();
    correctSum = findCorrectSum();
}

void Gameplay::initializeNumbers() {
    std::fill(reachable, reachable + MAX_SUM, false);
    reachable[0] = true;
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
    nextNumberTimer.stop();
    int interval = currentLevel->timeTillNextNumber();
    if (interval != -1) {
        nextNumberTimer.setSingleShot(true);
        nextNumberTimer.start(interval);
    }
}

void Gameplay::setLevelCountdownTimer() {
    levelCountdownTimer.stop();
    if (currentLevel->isTimed()) {
        levelCountdownTimer.start(currentLevel->getTime());
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
    if (currentLevel->completed() ||
        currentLevel->completed(numbers.size())) {
        iterateLevel();
    }
}

void Gameplay::prepare() {
    sumOfNumbers = 0;
    correctSum = -1;
    std::fill(reachable, reachable + MAX_SUM, false);
    reachable[0] = true;
    numbers = QVector<Number>();
    setNextNumberTimer();
    setLevelCountdownTimer();
}

void Gameplay::iterateLevel() {
    switch (currentLevel->getLevelNumber()) {
    case 1:
        currentLevel = new Level2();
        break;
    case 2:
        currentLevel = new Level3();
        break;
    };
    prepare();
}

void Gameplay::initialize() {
    reachable = new bool[MAX_SUM];
    currentLevel = new Level1();
    updateTimer.stop();
    disconnect(&nextNumberTimer, SIGNAL(timeout()), this, SLOT(addNumber()));
    disconnect(&levelCountdownTimer, SIGNAL(timeout()), this, SLOT(lose()));
    connect(&nextNumberTimer, SIGNAL(timeout()), this, SLOT(addNumber()));
    connect(&levelCountdownTimer, SIGNAL(timeout()), this, SLOT(lose()));
    prepare();
}

Gameplay::Gameplay() {
    initialize();
}

void Gameplay::lose() {
    initialize();
}

Gameplay::~Gameplay() {
    delete reachable;
    delete currentLevel;
}

int Gameplay::getNumbersCount() const {
	return numbers.size();
}

bool Gameplay::isTimed() const {
    return currentLevel->isTimed();
}

int Gameplay::getStartTime() const {
    return currentLevel->getTime();
}

int Gameplay::getTimeLeft() const {
    return levelCountdownTimer.remainingTime();
}

Number Gameplay::getNthNumber(int n) const {
	return numbers[n];
}

#define distance(A,B) sqrt(((A).x()-(B).x())*((A).x()-(B).x())\
    +((A).y()-(B).y())*((A).y()-(B).y()))

void Gameplay::handleUserClick(const QPointF &pos, const qreal CLICK_RADIUS) {
    for (Number &n : numbers) {
        if (distance(n.getPosition(), pos) < CLICK_RADIUS) {
            /* TODO: ładniejsze wykrywanie kliknięcia
             * w numerek */
            n.toggleSelected();
        }
    }
    update();
}
