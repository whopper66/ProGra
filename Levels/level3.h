#ifndef LEVEL3_H
#define LEVEL3_H

#include "../level.h"

class Level3 : public Level {

private:
    QVector<Number> queue;
    void Initialize();

public:
    int getLevelNumber() const;
    Level3();
    Number nextNumber();
    int timeTillNextNumber();
    bool completed(int numbersLeft) const;
    bool isTimed() const;
    int getTime() const;
};

#endif // LEVEL2_H
