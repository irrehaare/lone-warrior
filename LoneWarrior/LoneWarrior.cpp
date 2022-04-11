#include "Tile.h"

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

#include <iostream>

int main()
{
    // Logger start
    plog::init(plog::debug, "Logfile.txt");
    PLOGD << "Starting application...";

    // Content
    std::cout << "Hello World!\n";
    Tile tile('+');
    printf("%c\n", tile.getSymbol());

    // Finalize
    return 0;
}