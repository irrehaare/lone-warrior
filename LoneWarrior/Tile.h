#pragma once
#include "Entity.h"
#include <optional>

class Tile
{
private:
	char16_t tileSymbol;
	std::optional<Entity*> pEntity;

public:
	explicit Tile(char16_t symbol);
	char16_t getSymbol();
	void setEntity(Entity* pEntity);
	void clearEntity();
};
