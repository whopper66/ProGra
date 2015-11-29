#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Levels/level1.h"

#include <QTimer>
#include <QVector>

#include <QDebug>

const int MAX_SUM = 16500;

class Gameplay : private QObject {
    Q_OBJECT

private:
    QTimer updateTimer;
    QVector<Number> numbers;
    int sumOfNumbers;
    /* do sprawdzania, które sumy są osiągalne */
    int correctSum;
    /* tyle, ile gracz powinien uzyskać, nie mam pomysłu
     * na lepszą nazwę */
    bool *reachable;
    Level *currentLevel;

    void addNumber(Number n);
    int findCorrectSum();
    void initializeNumbers();
    void deleteSelectedNumbers();


protected:

public:
    Gameplay();
    ~Gameplay();
    int getNumbersCount() const;
    Number getNthNumber(int n) const;
};

#endif // GAMEPLAY_H
