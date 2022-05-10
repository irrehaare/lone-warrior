#include "Engine.h"
#include "Map.h"

#include <iostream>
#include <conio.h>

constexpr auto KEY_UP = 72;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;
constexpr auto KEY_DOWN = 80;
constexpr auto END_GAME_BUTTON = 'Q';

void Engine::playGame()
{
    map.getGrid()[2][2].setEntity(&player);
    isOngoing = true;
    while (isOngoing) 
    {
        processTurn();
    }
}

void Engine::processTurn()
{
    int input = getInput();
    if (input == END_GAME_BUTTON) {
        isOngoing = false;
    }
    printf("%d\n", input);
    display.refresh(&map);
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

