#include "gameplay.h"

Gameplay::Gameplay() {

    updateTimer.start(UPDATE_INTERVAL);
    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));

}

void Gameplay::update() {

}
