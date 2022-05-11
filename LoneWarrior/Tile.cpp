#include "Tile.h"

Tile::Tile(char16_t tileSymbol) : tileSymbol(tileSymbol) {}

char16_t Tile::getSymbol()
{
	if (pEntity.has_value())
	{
		return pEntity.value()->getSymbol();
	}
	return tileSymbol;
}

void Tile::setEntity(Entity* newPEntity)
{
	this->pEntity = newPEntity;
}

void Tile::clearEntity()
{
	pEntity.reset();
}
