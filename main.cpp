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
    int a =1;
    int control = 0;
    console::init();
    double targetFrameDuration = 1.0/MOVE_DELAY;
    int score = 0;
    while(true)
    {
        console::clear();
        std::clock_t frameStart = std::clock();

        std::string scorePrint = "Score: ";
        scorePrint.insert(scorePrint.size() , std::to_string(score));
        drawWall();
        // console::draw(3,3,"Hello");
       
        if(console::key(console::K_LEFT) && control != 2)
            control = 0;
    
        else if(console::key(console::K_UP) && control != 3)
            control = 1;

        else if(console::key(console::K_RIGHT) && control != 0)
            control = 2;

        else if(console::key(console::K_DOWN) && control != 1)
            control = 3;
        
       
        if(control == 0)
            x--;

        else if(control == 1)
            y--;

        else if(control == 2)
            x++;

        else if (control == 3)
            y++;
        
        
 
        console::draw(x,y ,SNAKE_STRING);
        console::draw(7, BOARD_SIZE ,scorePrint);

        if (console::key(console::K_ESC))
        {
            break;
        }

        // while(a != (int)(((double)(frameStart)/CLOCKS_PER_SEC)/targetFrameDuration))
        // {
        //     console::wait();
        // }
        // a++;
        while(clock() - frameStart < targetFrameDuration * CLOCKS_PER_SEC)
        {
            console::wait();
        }
        
        // else
        // {
        //     console::wait();
        // }
        // console::wait();
       

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

