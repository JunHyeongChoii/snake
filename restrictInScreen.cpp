#include "console.h"

void restrictInScreen(int& x, int& y, int boardSize) {
  // x, y 위치를 화면의 최대 크기에서 벗어나지 않게 한다.
  if (x <= 0)
    x = 0;
  if (x >= console::SCREEN_WIDTH -(console::SCREEN_WIDTH - boardSize) )
    x = console::SCREEN_WIDTH - (console::SCREEN_WIDTH - boardSize)- 1;
  if (y <= 0)
    y = 0;
  if (y >= console::SCREEN_HEIGHT -(console::SCREEN_HEIGHT - boardSize) )
    y = console::SCREEN_HEIGHT - (console::SCREEN_HEIGHT - boardSize)- 1;
}