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
void handleInput(int& control, int& x, int &y);


int main()
{
    
    game();
}

int control = 0;


void game()
{
    int a =1;
    
    console::init();
    double targetFrameDuration = 1.0/MOVE_DELAY;
    int score = 0;
    
    while(true)
    {
        std::clock_t frameStart = std::clock();
        console::clear();
        

        std::string scorePrint = "Score: ";
        scorePrint.insert(scorePrint.size() , std::to_string(score));
        drawWall();
        // console::draw(3,3,"Hello");
       
        // if(console::key(console::K_LEFT) && control != 2)
        //     control = 0;
    
        // else if(console::key(console::K_UP) && control != 3)
        //     control = 1;

        // else if(console::key(console::K_RIGHT) && control != 0)
        //     control = 2;

        // else if(console::key(console::K_DOWN) && control != 1)
        //     control = 3;

        handleInput(control, x, y);
       
        // if(control == 0)
        //     x--;

        // else if(control == 1)
        //     y--;

        // else if(control == 2)
        //     x++;

        // else if (control == 3)
        //     y++;
        
        
 
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
        while(true)
        {
            clock_t current = clock();
            double dd = (double)(current - frameStart) / CLOCKS_PER_SEC;
            if(targetFrameDuration <= dd)
            {
                break;
            }
                
            
            else
            {
                console::wait();
            }
        }
        
        
        // else
        // {
        //     console::wait();
        // }
        // console::wait();
       

    }
}





// int& handleInput(int &control)
// {
//     if(console::key(console::K_LEFT) && control != 2)
//         control = 0;
    
//     else if(console::key(console::K_UP) && control != 3)
//         control = 1;

//     else if(console::key(console::K_RIGHT) && control != 0)
//         control = 2;

//     else if(console::key(console::K_DOWN) && control != 1)
//         control = 3;
//     else
//     {
//         return control;
//     }
// }