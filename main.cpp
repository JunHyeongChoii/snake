#include <iostream>
#include <string>

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

int x = 0;
int y = 0;

void game();
void drawWall();
int main()
{
    
    game();
}

void game()
{
    console::init();

    while(true)
    {
        console::clear();
        
        drawWall();
        console::draw(3,3,"Hello");
         if (console::key(console::K_ESC))
        {
            break;
        }
       
        console::wait();
       
    }
}

