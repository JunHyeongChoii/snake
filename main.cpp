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
void restrictInScreen(int & x, int& y, int boardSize);
bool finishGameBad(int & x,int& y, int boardSize);


int main()
{
    
    game();
}

int control = 0;


void game()
{
    int tail = 1;
    const int sizeXY = (BOARD_SIZE - 2) * 2;
    int tail_x [sizeXY];
    int tail_y [sizeXY];

    int appleX = 0;
    int appleY = 0;

   
    double targetFrameDuration = 1.0/MOVE_DELAY;

    int score = 0;

    
    console::init();
    
    while(true)
    {
        const int notTailXySize = (BOARD_SIZE - 2) * 2 - tail;
        int notTailX[notTailXySize];
        int notTailY[notTailXySize];

        std::clock_t frameStart = std::clock();
        console::clear();
        

        std::string scorePrint = "Score: ";
        scorePrint.insert(scorePrint.size() , std::to_string(score));
        drawWall();

        handleInput(control, x, y);
       
        restrictInScreen(x,y,BOARD_SIZE);
        console::draw(x,y ,SNAKE_STRING);
        

        finishGameBad(x,y, BOARD_SIZE);
        
        console::draw(7, BOARD_SIZE ,scorePrint);

        
        if (console::key(console::K_ESC))
        {
            break;
        }
        int endGame = finishGameBad(x,y,BOARD_SIZE);

        if( endGame == 0)
        {
            console::draw(5, 10,"YOU LOSE!");
            console::draw(1, 11,"Try again? (Enter)");
            
        }
       
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


