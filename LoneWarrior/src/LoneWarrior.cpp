#include "Engine.h"

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

#include <iostream>

int main()
{
    // Logger start
    plog::init(plog::debug, "Logfile.txt");
    PLOGD << "Starting application...";

    // App start
    Engine engine;

    // App test
    engine.playGame();

    // Finalize
    return 0;
}