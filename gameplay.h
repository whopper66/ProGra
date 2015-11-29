#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "level.h"

#include <QTimer>
#include <QVector>

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
    void addNumber(Number n);
    int findCorrectSum();
    void initializeNumbers();

    void deleteSelectedNumbers();

    Level *currentLevel;

protected:

public:

    Gameplay();

};

#endif // GAMEPLAY_H
