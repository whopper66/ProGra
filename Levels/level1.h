#ifndef LEVEL1_H
#define LEVEL1_H

#include "../level.h"

class Level1 : Level {

private:
    void Initialize();

public:
    Level1();
    Number nextNumber();
};

#endif // LEVEL1_H
