#pragma once
#include "Tile.h"
#include "Map.h"

class Display
{
public:
	void refresh(Map*) const;

private:
	void clear() const;
};

