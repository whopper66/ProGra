#ifndef LEVEL1_H
#define LEVEL1_H

#include "../level.h"

class Level1 : public Level {

private:
	QVector<Number> queue;
	void Initialize();

public:
    int getLevelNumber() const;
	Level1();
	Number nextNumber();
	int timeTillNextNumber();
    bool completed(int numbersLeft) const;
    bool isTimed() const;
    int getTime() const;
};

#endif // LEVEL1_H
