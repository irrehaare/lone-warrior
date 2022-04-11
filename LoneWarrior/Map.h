#pragma once
#include "Tile.h"

class Map
{
private:
	Tile grid[20][10];

public:
	Tile** getGrid();
};