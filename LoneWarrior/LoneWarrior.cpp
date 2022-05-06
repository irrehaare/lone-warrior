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
        for (int j = 0; j < map.getGrid().at(i).size(); j++)
        {
            printf("%c", map.getGrid().at(i).at(j).getSymbol());
            printf("\n");
        }
    }

    // Finalize
    return 0;
}