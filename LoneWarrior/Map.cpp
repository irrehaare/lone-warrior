#include "Map.h"
#include "Tile.h"

Map::Map(int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		grid[i] = std::vector<Tile>();
		for (int j = 0; j < width; j++)
		{
			grid.at(i).push_back(Tile('.'));
		}
	}
}

std::vector<std::vector<Tile>> Map::getGrid() const
{
	return grid;
}
