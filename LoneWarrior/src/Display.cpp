#include "Display.h"
#include <iostream>

void Display::refresh(Map* pMap) const
{
    clear();
    for (int i = 0; i < (*pMap).getGrid().size(); i++)
    {
        for (int j = 0; j < (*pMap).getGrid()[i].size(); j++)
        {
            printf("%c", (*pMap).getGrid()[i][j].getSymbol());
        }
        printf("\n");
    }
}

void Display::clear() const
{
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}
