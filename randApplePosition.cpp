#include <ctime>
#include <cstdlib>

#define BOARD_SIZE 20


void randApplePosition(int& appleX, int& appleY, int tail,int tailX[], int tailY[], int bs)
{
   
    srand(static_cast<unsigned int>(time(nullptr)));
    const int applePosCount = (bs-2) * (bs-2) -tail;
    int canApplePosition [applePosCount] = {0};
    
    const int boardSize = bs;
    
    const int board = (boardSize-2) * (boardSize-2);
    
    int XorY [boardSize][boardSize] = {0};

    for(int i = 1; i< boardSize-1; i++)
    {
        for(int j = 1; j<boardSize-1; j++)
        {
            
            XorY[i][j] = 1;
            
        }
    }


    for(int i = 0; i<tail; i++)
    {
        int xxx = tailX[i];
        int yyy = tailY[i];
        XorY[xxx][yyy] = 0;
    }

    int k = 0;
    for(int i = 0; i<boardSize; i++)
    {
        for(int j = 0; j<boardSize; j++)
        {
            if(XorY[i][j] == 1)
            {
                canApplePosition[k] = i*100 + j;
                k++;
            }
        }
    }
    

    appleX = canApplePosition[rand() % applePosCount ] / 100;
    appleY = canApplePosition[rand() % applePosCount ] % 100;
}