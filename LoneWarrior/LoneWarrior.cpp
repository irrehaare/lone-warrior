#include "Tile.h"
#include "Map.h"

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

#include <iostream>

int main()
{
    // Logger start
    plog::init(plog::debug, "Logfile.txt");
    PLOGD << "Starting application...";

    // Tile test
    std::cout << "Hello World!\n";
    Tile tile('+');
    printf("%c\n", tile.getSymbol());

    //Map test
    Map map(7, 5);
    for (int i = 0; i < map.getGrid().size(); i++)
    {
        printf("%c", map.getGrid().at(i).getSymbol());
    }

    // Finalize
    return 0;
}