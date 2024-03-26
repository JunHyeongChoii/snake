#include "console.h"

void handleInput(int& control, int& x, int& y)
{
    if(console::key(console::K_LEFT) && control != 2)
        control = 0;
    
    else if(console::key(console::K_UP) && control != 3)
        control = 1;

    else if(console::key(console::K_RIGHT) && control != 0)
        control = 2;

    else if(console::key(console::K_DOWN) && control != 1)
        control = 3;
    else
    {
        control;
    }


    if(control == 0)
        x--;

    else if(control == 1)
        y--;

    else if(control == 2)
        x++;

    else if (control == 3)
        y++;
}