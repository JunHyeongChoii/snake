#include "console.h"

#define BOARD_SIZE 20
#define MOVE_DELAY 60
#define WALL_VERTICAL_STRING "┃"
#define WALL_HORIZONTAL_STRING "━"
#define WALL_RIGHT_TOP_STRING "┓"
#define WALL_LEFT_TOP_STRING "┏"
#define WALL_RIGHT_BOTTOM_STRING "┛"
#define WALL_LEFT_BOTTOM_STRING "┗"
#define SNAKE_STRING "■"
#define SNAKE_BODY_STRING "■"
#define APPLE_STRING "●"

void drawWall()
{
    for (int i = 0; i < BOARD_SIZE +1 ; i++)
    {
        for(int j = 0; j < BOARD_SIZE +1 ; j++)
        {
            if(i == 0 && j == 0)
                console::draw(i,j ,WALL_LEFT_TOP_STRING);

            else if ( i == BOARD_SIZE && j == 0)
                console::draw(i,j , WALL_RIGHT_TOP_STRING);

            else if( i == 0 && j== BOARD_SIZE)
                console::draw(i,j, WALL_LEFT_BOTTOM_STRING);

            else if(i == BOARD_SIZE && j == BOARD_SIZE)
                console::draw(i,j, WALL_RIGHT_BOTTOM_STRING);

            else if( (i>0 && i<BOARD_SIZE) && (j == 0 || j==BOARD_SIZE ))
                console::draw(i,j, WALL_HORIZONTAL_STRING);

            else if( (i == 0 || i == BOARD_SIZE) && (j >0 && j<BOARD_SIZE))
                console::draw(i,j, WALL_VERTICAL_STRING);   

            
        }
    }
}