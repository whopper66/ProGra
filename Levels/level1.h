#ifndef LEVEL1_H
#define LEVEL1_H

#include "../level.h"

class Level1 : public Level {

private:
    QVector<Number> queue;
    void Initialize();

public:
	Level1();
	Number nextNumber();
	int timeTillNextNumber();
};

#endif // LEVEL1_H
