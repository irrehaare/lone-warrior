#pragma once
class Tile
{
private:
	char symbol;

public:
	explicit Tile(char symbol);

	char getSymbol() const { return symbol; }
};
