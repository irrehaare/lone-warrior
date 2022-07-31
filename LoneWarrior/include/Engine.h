#pragma once
#include "Display.h"
#include "Map.h"
#include "Entity.h"

class Engine
{
private:
	Display display;
	Map map = Map(5, 10);
	Entity player = Entity('@');
	bool isOngoing = false;

	void processTurn();
	int getInput() const;
	void makeStep(int input);
	std::pair<int, int> mapInputToCoordintesChange(int input) const;
	void moveEntity(Entity* entity, int xChange, int yChange);
	int getNewCoordinate(int oldCoordinate, int change, int size) const;
	void finishGame();

public:
	explicit Engine() =default;
	void playGame();
};

