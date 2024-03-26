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
    int a =1;
    
    console::init();
    double targetFrameDuration = 1.0/MOVE_DELAY;
    int score = 0;
    int appleX = 0;
    int appleY = 0;

    std::string playerSize = "";
    while(true)
    {
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





// void restrictInScreen(int& x, int& y) {
//   // x, y 위치를 화면의 최대 크기에서 벗어나지 않게 한다.
//   if (x < 0)
//     x = 0;
//   if (x >= console::SCREEN_WIDTH)
//     x = console::SCREEN_WIDTH - 1;
//   if (y < 0)
//     y = 0;
//   if (y >= console::SCREEN_HEIGHT)
//     y = console::SCREEN_HEIGHT - 1;
// }

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