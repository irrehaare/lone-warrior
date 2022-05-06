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

    // Tile test
    Tile tile('+');
    printf("%c\n", tile.getSymbol());

    //Map test
    Map map(7, 5);
    for (int i = 0; i < map.getGrid().size(); i++)
    {
        for (int j = 0; j < map.getGrid()[i].size(); j++)
        {
            printf("%c", map.getGrid()[i][j].getSymbol());
        }
        printf("\n");
    }

    // Finalize
    return 0;
}