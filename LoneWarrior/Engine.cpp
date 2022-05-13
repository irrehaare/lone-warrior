#include "Engine.h"
#include "Map.h"

#include <iostream>
#include <conio.h>

constexpr auto KEY_UP = 72;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;
constexpr auto KEY_DOWN = 80;

constexpr auto UP = 1;
constexpr auto LEFT = 3;
constexpr auto RIGHT = 4;
constexpr auto DOWN = 2;

constexpr auto END_GAME_BUTTON = 'Q';

void Engine::playGame()
{
    map.getGrid()[2][2].setEntity(&player);
    player.setCoodrinates(2, 2);
    
    Entity column('#');
    map.getGrid()[2][3].setEntity(&column);
    column.setCoodrinates(2, 3);

    isOngoing = true;
    display.refresh(&map);
    while (isOngoing) 
    {
        processTurn();
    }
}

void Engine::processTurn()
{
    int input = getInput();
    switch (input)
    {
    case UP:
    case DOWN:
    case LEFT:
    case RIGHT:
        makeStep(input);
        break;
    case END_GAME_BUTTON:
        finishGame();
        break;
    default:
        break;
    }

    display.refresh(&map);
    printf("%d\n", input);
}

void Engine::makeStep(int input)
{
    auto [xChange, yChange] = mapInputToCoordintesChange(input);
    moveEntity(&player, xChange, yChange);
}

std::pair<int, int> Engine::mapInputToCoordintesChange(int input) const
{
    switch (input)
    {
    case UP:
        return std::pair<int, int>(0, -1);
    case LEFT:
        return std::pair<int, int>(-1, 0);
    case RIGHT:
        return std::pair<int, int>(1, 0);
    case DOWN:
        return std::pair<int, int>(0, 1);
    default:
        return std::pair<int, int>(0, 0);
    }
}

void Engine::moveEntity(Entity* entity, int xChange, int yChange)
{
    int oldX = (*entity).getX();
    int oldY = (*entity).getY();

    int newX = getNewCoordinate(oldX, xChange, static_cast<int>(map.getGrid()[0].size()));
    int newY = getNewCoordinate(oldY, yChange, static_cast<int>(map.getGrid().size()));

    //Check for collision, currently simply cancells movement
    if (!map.getGrid()[newY][newX].getEntity().has_value()) 
    {
        map.getGrid()[oldY][oldX].clearEntity();
        map.getGrid()[newY][newX].setEntity(entity);
        (*entity).setCoodrinates(newX, newY);
    }
}

// Includes check to stay within the map
int Engine::getNewCoordinate(int oldCoordinate, int change, int size) const
{
    int newCoordinate = oldCoordinate + change;
    if (newCoordinate >= size)
    {
        newCoordinate = size - 1;
    }
    else if (newCoordinate < 0)
    {
        newCoordinate = 0;
    }
    return newCoordinate;
}

void Engine::finishGame()
{
    isOngoing = false;
}


int Engine::getInput() const
{
    int c;
    c = _getch();

    if (c && c != 224)
    {
        return c;
    }
    else
    {
        switch (_getch())
        {
        case KEY_UP     /* H */:
            return 1;
        case KEY_DOWN   /* K */:
            return 2;
        case KEY_LEFT   /* M */:
            return 3;
        case KEY_RIGHT: /* P */
            return 4;
        default:
            return 0;
        }
    }
}
