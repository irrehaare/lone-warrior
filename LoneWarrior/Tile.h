#pragma once

class Tile
{
private:
	char16_t symbol;

public:
	explicit Tile(char symbol);

	char16_t getSymbol() const { return symbol; }
};
