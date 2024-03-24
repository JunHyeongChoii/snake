#include <iostream>
#include <string>
#include <ctime>

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

int x = (BOARD_SIZE-1)/2;
int y = (BOARD_SIZE-1)/2;



void game();
void drawWall();
int handleInput();


int main()
{
    
    game();
}



void game()
{
    int control = 0;
    console::init();
    const double targetFrameDuration = 1.0 / MOVE_DELAY ;
    while(true)
    {
        console::clear();
        std::clock_t frameStart = std::clock();


        drawWall();
        // console::draw(3,3,"Hello");
        if(console::key(console::K_LEFT))
            control = 0;
    
        else if(console::key(console::K_UP))
            control = 1;

        else if(console::key(console::K_RIGHT))
            control = 2;

        else if(console::key(console::K_DOWN))
            control = 3;
        

        if(control == 0)
            x--;

        else if(control == 1)
            y--;

        else if(control == 2)
            x++;

        else if (control == 3)
            y++;
        
        std::clock_t frameEnd = std::clock();
 
        console::draw(x,y ,SNAKE_STRING);

        if (console::key(console::K_ESC))
        {
            break;
        }
       
        while(targetFrameDuration <frameEnd - frameStart)
        {
            console::wait();
        }

    }
}




int handleInput()
{
    if(console::key(console::K_LEFT))
        return  0;
    
    else if(console::key(console::K_UP))
        return  1;

    else if(console::key(console::K_RIGHT))
        return  2;

    else if(console::key(console::K_DOWN))
        return  3;
}

