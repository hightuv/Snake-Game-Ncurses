#include "render.h"

Render::Render(char stage) {
  Map map(stage);
  // game window
  initUI();
}

void Render::initUI() {
  snakeWindow = newwin(21, 42, 5, 5);
  start_color();
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  wbkgd(snakeWindow, COLOR_PAIR(2));
  wrefresh(snakeWindow);
  updateUI();
  //delwin(snakeWindow);
  //endwin();
}

void Render::updateUI() {
  int row = 21;
  int col = 21;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++){
      char c = map.getMapData(i, j);
      if (c == WALL || c == IMMUNEWALL) {
        mvwprintw(snakeWindow, row, col*2, "\u25A1");
      }
      else if (c == EMPTY) {
        mvwprintw(snakeWindow, row, col*2, "\u0020");
      }
      else if (c == SNAKE) {
        mvwprintw(snakeWindow, row, col*2, "\u25CB");
      }
    }
  }
  wrefresh(snakeWindow);
}
//
// void Render::endWindow() {
//   delwin(snakeWindow);
// }
