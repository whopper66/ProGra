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
    virtual Number nextNumber();
    virtual int timeTillNextNumber();
    Level();
};

#endif // LEVEL_H
