#include "Display.h"

void Display::refresh(Map* pMap)
{
    for (int i = 0; i < (*pMap).getGrid().size(); i++)
    {
        for (int j = 0; j < (*pMap).getGrid()[i].size(); j++)
        {
            printf("%c", (*pMap).getGrid()[i][j].getSymbol());
        }
        printf("\n");
    }
}
