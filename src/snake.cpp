#include "snake.h"

Snake::Snake() {
  initUI();
}

void Snake::initUI() {
  // unicode
  setlocale(LC_ALL, "");
  // start Curses mode
  initscr();
  // color use declare
  start_color();
  // start menu font color, bg color
  init_pair(1, COLOR_RED, COLOR_WHITE);
  // set bg color
  bkgd(COLOR_PAIR(1));
  // no curse
  curs_set(0);
  // border
  border('*', '*', '*', '*', '*', '*', '*', '*');
  // text
  mvprintw(5, 5, "Snake Game!");
  for(int i=0; i<4; i++)
    mvprintw(i+6, 5, "%d. Stage %d" ,i+1, i+1);

  // refresh window
  refresh();
  // wait for input
  getch();
  endwin();
}
