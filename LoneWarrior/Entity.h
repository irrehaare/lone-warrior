#pragma once
class Entity
{
private:
	char16_t symbol;

public:
	explicit Entity(char symbol);

	char16_t getSymbol() const { return symbol; }
};

