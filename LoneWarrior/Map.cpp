#include "Map.h"
#include "Tile.h"

Map::Map(int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		grid.push_back(Tile('.'));
	}
}

std::vector<Tile> Map::getGrid()
{
	return grid;
}
