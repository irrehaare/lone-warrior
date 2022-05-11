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

    isOngoing = true;
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
    case END_GAME_BUTTON:
        finishGame();
        break;
    case UP:
    case DOWN:
    case LEFT:
    case RIGHT:
        movePlayer(input);
        break;
    default:
        break;
    }

    display.refresh(&map);
    printf("%d\n", input);
}

void Engine::movePlayer(int input)
{
    int oldX = player.getX();
    int oldY = player.getY();
    auto [xChange, yChange] = mapInputToCoordintesChange(input);
    map.getGrid()[oldY + yChange][oldX + xChange].setEntity(&player);
    map.getGrid()[oldY][oldX].clearEntity();
    player.setCoodrinates(oldX + xChange, oldY + yChange);
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
