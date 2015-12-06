#ifndef LEVEL2_H
#define LEVEL2_H

#include "../level.h"

class Level2 : public Level {

private:
    QVector<Number> queue;
    void Initialize();

public:
    Level2();
    Number nextNumber();
    int timeTillNextNumber();
};

#endif // LEVEL2_H
