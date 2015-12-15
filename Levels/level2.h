#ifndef LEVEL2_H
#define LEVEL2_H

#include "../level.h"

class Level2 : public Level {

private:
    QVector<Number> queue;
    void Initialize();

public:
    int getLevelNumber() const;
    Level2();
    Number nextNumber();
    int timeTillNextNumber();
    bool completed(int numbersLeft) const;
};

#endif // LEVEL2_H
