#include <ctime>
#include <cstdlib>

#define BOARD_SIZE 20


void randApplePosition(int& appleX, int& appleY, int tail,int tailX[], int tailY[])
{
   
    srand(static_cast<unsigned int>(time(nullptr)));
    const int applePosCount = (BOARD_SIZE-2) * (BOARD_SIZE-2) -tail;
    int canApplePosition [applePosCount] = {0};
    
    const int boardSize = BOARD_SIZE;
    
    const int board = (BOARD_SIZE-2) * (BOARD_SIZE-2);
    
    int XorY [BOARD_SIZE][BOARD_SIZE] = {0};

    for(int i = 1; i< BOARD_SIZE-1; i++)
    {
        for(int j = 1; j<BOARD_SIZE-1; j++)
        {
            
            XorY[i][j] = 1;
            
        }
    }


    for(int i = 0; i<tail; i++)
    {
        const int xxx = tailX[i];
        const int yyy = tailY[i];
        XorY[xxx][yyy] = 0;
    }

    int k = 0;
    for(int i = 0; i<BOARD_SIZE; i++)
    {
        for(int j = 0; j<BOARD_SIZE; j++)
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