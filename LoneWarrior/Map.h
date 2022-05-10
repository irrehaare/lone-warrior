#pragma once
#include "Tile.h"
#include <vector>

class Map
{
private:
	std::vector<std::vector<Tile>> grid;

public:
	Map(int height, int width);
	std::vector<std::vector<Tile>>& getGrid();
};

