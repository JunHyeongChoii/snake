#include "console.h"

bool finishGameBad(int& x, int & y, int boardSize)
{
    if(x == 0 or x == boardSize-1)
    {
        return 0;
    }
    if(y == 0 or y == boardSize -1)
    {
        return 0;
    }

    return 1;
}