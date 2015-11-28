#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "number.h"

#include <QTimer>
#include <QVector>

/* czas pomiędzy wywołaniami metody update() */
const int UPDATE_INTERVAL = 10; //milis

class Gameplay : private QObject {
    Q_OBJECT

private:
    QTimer updateTimer;
    QVector<Number> numbers;

private slots:
    void update();

protected:

public:

    Gameplay();

};

#endif // GAMEPLAY_H
