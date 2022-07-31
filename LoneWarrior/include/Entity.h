#pragma once
class Entity
{
private:
	char16_t symbol;
	int x;
	int y;

public:
	explicit Entity(char symbol);

	char16_t getSymbol() const { return symbol; }

	int getX() const { return x; }
	int getY() const { return y; }

	void setCoodrinates(int newX, int newY) 
	{ 
		x = newX; 
		y = newY;
	}

};

