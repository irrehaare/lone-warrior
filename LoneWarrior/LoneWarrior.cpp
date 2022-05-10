#include "Display.h"
#include "Tile.h"
#include "Map.h"

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

#include <iostream>
#include "Tile.h"

using namespace std;

int main()
{
    // Logger start
    plog::init(plog::debug, "Logfile.txt");
    PLOGD << "Starting application...";

    // App start
    Display display;

    //App test
    Map map(3, 1);
    Entity player('@');
    map.getGrid()[0][0].setEntity(&player);
    display.refresh(&map);

    // Finalize
    return 0;
}