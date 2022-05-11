#pragma once
#include "Display.h"
#include "Map.h"
#include "Entity.h"

class Engine
{
private:
	Display display;
	Map map = Map(20, 40);
	Entity player = Entity('@');
	bool isOngoing = false;

	void processTurn();
	int getInput() const;
	void movePlayer(int input);
	std::pair<int, int> mapInputToCoordintesChange(int input) const;
	void finishGame();

public:
	explicit Engine() =default;
	void playGame();
};

