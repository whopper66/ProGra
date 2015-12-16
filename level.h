#ifndef LEVEL_H
#define LEVEL_H

/* To jest tylko base klasa, a wszystkie
 * poziomy będą w plikach Levels/levelX.h/cpp.
 * Dzięki temu poziomy nie będą musiały się różnić tylko
 * parametrami, a będzie można niektóre "oskryptować" */

#include "number.h"

#include <QVector>

class Level {

private:

protected:
	virtual void Initialize();

public:
    virtual int getLevelNumber() const;
	virtual Number nextNumber();
    virtual int timeTillNextNumber(); /* -1 for infinity */
	Level();
	virtual ~Level();

    virtual bool isTimed() const;
    virtual int getTime() const;
    /* -1 for infinity */

    virtual bool completed() const;
    virtual bool completed(int numbersLeft) const;
    /* UWAGA: można dodawać metody completed()
     * różnymi zbiorami argumentów, a następnie
     * w kodzie sprawdzać je po kolei */
};

#endif // LEVEL_H
