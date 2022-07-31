#include "Map.h"
#include "Tile.h"

Map::Map(int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		grid.emplace_back();
		for (int j = 0; j < width; j++)
		{
			grid[i].emplace_back('.');
		}
	}
}

std::vector<std::vector<Tile>>& Map::getGrid()
{
	return grid;
}
