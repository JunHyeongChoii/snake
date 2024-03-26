#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "console.h"

#define BOARD_SIZE 20
#define MOVE_DELAY 5
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
void randApplePosition(int& appleX, int& appleY, int tail,int tailX[], int tailY[],int bs);
bool selfCarsh(int x, int y, int tailX[], int tailY[], int tail);


int main()
{
    
    game();
}

int control = 0;


void game()
{
    int tail = 1;
    const int sizeXY = (BOARD_SIZE - 2) *(BOARD_SIZE - 2) ;
    int tailX [sizeXY] = {0};
    int tailY [sizeXY] = {0};

    int appleX = 0;
    int appleY = 0;

    
   
    double targetFrameDuration = 1.0/MOVE_DELAY;

    int score = 0;
    int scoreX = 7;
    int scoreLength = 8;
    int endGame = 1;
    tailX[0] = x;
    tailY[0] = y;
    randApplePosition(appleX, appleY, tail, tailX, tailY, BOARD_SIZE);

    console::init();
    
    while(true)
    {
 
        tailX[0] = x;
        tailY[0] = y;
        
        
        
        std::clock_t frameStart = std::clock();
        console::clear();
        
        
        drawWall();
        if(endGame == 1)
        {
            handleInput(control, x, y);
            if(tail >1)
            {
                for(int i = tail; i>=0; i--)
                {
                    if(i == 0)
                    {
                        tailX[i] = x;
                        tailY[i] = y;

                    }
                    else
                    {
                        tailX[i] = tailX[i-1];
                        tailY[i] = tailY[i-1];
                    }
                }
            }
        }
        
        
       
        restrictInScreen(x,y,BOARD_SIZE);



        console::draw(appleX, appleY,APPLE_STRING);

        for(int i = 0; i<tail; i++)
        {
            console::draw(tailX[i],tailY[i] ,SNAKE_STRING);
        }
        
        


        std::string scorePrint = "Score: ";
        scorePrint.insert(scorePrint.size() , std::to_string(score));
        
        if(scorePrint.size() > scoreLength)
        {
            scoreX -=1;
            scoreLength = scorePrint.size();
        }

        console::draw(scoreX, BOARD_SIZE ,scorePrint);

        
        if (console::key(console::K_ESC))
        {
            break;
        }


        endGame = finishGameBad(x,y,BOARD_SIZE);
        int endSCGame = selfCarsh(x, y, tailX, tailY, tail);

        if((x == appleX) && (y == appleY))
        {
            tail++;
            score += 10;
            randApplePosition(appleX, appleY, tail, tailX, tailY, BOARD_SIZE);
        }

        if( endGame == 0 || endSCGame==0)
        {
            console::draw(5, 10,"YOU LOSE!");
            console::draw(1, 11,"Try again? (Enter)");
            
            if(console::key(console::K_ENTER))
            {

                for(int i = 0; i<tail; i++)
                {
                    tailX[i] = 0;
                    tailY[i] = 0;
                }

                tail = 1;
                x = (BOARD_SIZE-1)/2;
                y = (BOARD_SIZE-1)/2;
                scoreX = 7;
                control = 0;
                score =0;
                randApplePosition(appleX, appleY, tail, tailX, tailY,BOARD_SIZE);
 
            }
            
        }
        if(tail == (BOARD_SIZE-2) * (BOARD_SIZE-2))
        {
            console::draw(5, 10,"YOU WIN!");
            console::draw(1, 11,"Try again? (Enter)");

            if(console::key(console::K_ENTER))
            {

                for(int i = 0; i<tail; i++)
                {
                    tailX[i] = 0;
                    tailY[i] = 0;
                }

                tail = 1;
                x = (BOARD_SIZE-1)/2;
                y = (BOARD_SIZE-1)/2;
                scoreX = 7;
                control = 0;
                score =0;
                randApplePosition(appleX, appleY, tail, tailX, tailY,BOARD_SIZE);
 
            }
        }
        
       
        while(true)
        {
            clock_t current = clock();
            double fpsSixty = (double)(current - frameStart) / CLOCKS_PER_SEC;
            if(targetFrameDuration <= fpsSixty)
            {
                break;
            }
            else
            {
                console::wait();
            }
           
        }
        
        
    }
}

bool selfCarsh(int x, int y, int tailX[], int tailY[],int tail)
{
    
    for(int i = 1; i<tail; i++)
    {
        if( x == tailX[i] && y == tailY[i])
            return 0;
    }
    return 1;
}