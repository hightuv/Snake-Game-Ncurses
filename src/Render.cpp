#include "Render.h"

Render::Render() {
  newWindow = newwin(21, 21, 0, 0);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  wbkgd(newWindow, COLOR_PAIR(1));
  wattron(newWindow, COLOR_PAIR(1));
}

void Render::updateScreen() {
  int row = 21;
  int col = 21;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++){
      char c = map.getMapData(i, j);
      if (c == WALL || c == IMMUNEWALL) {
        mvwprintw(newWindow, row, col*2, "\u25A1");
      }
      else if (c == EMPTY) {
        mvwprintw(newWindow, row, col*2, "\u0020");
      }
      else if (c == SNAKE) {
        mvwprintw(newWindow, row, col*2, "\u25CB");
      }
    }
  }
  wrefresh(newWindow);
}

void Render::endWindow() {
  delwin(newWindow);
}
