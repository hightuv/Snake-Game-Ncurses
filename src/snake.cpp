#include "snake.h"
#define COL 21
#define ROW 21

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
  // key input
  keypad(stdscr, TRUE);
  // no write in window
  noecho();


  // text
  mvprintw(5, 5, "Snake Game!");
  for(int i=0; i<4; i++)
    mvprintw(i+6, 5, "%d. Stage %d" ,i+1, i+1);

  // choose stage
  char stage = '1';
  while(true) {
    stage = getch();
    if(stage=='1' || stage=='2' || stage=='3' || stage=='4')
     break;
  }

  Render render(stage);

  // render game window
  while(true) {
    break;
    for(int row=0; row<ROW; row++) {
      for(int col=0; col<COL; col++) {
        // mvprintw
      }
    }
  }

  // refresh window
  refresh();
  // wait for input
  getch();
  endwin();
}
