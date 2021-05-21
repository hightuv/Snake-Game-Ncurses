#include "render.h"

Render::Render(int stage) {
  Map map(stage);
  // game window
  newWindow = newwin(21, 21, 5, 5);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  wbkgd(newWindow, COLOR_PAIR(1));
  wborder(newWindow, '@', '@', '@', '@', '@', '@', '@', '@');
  wrefresh(newWindow);

  getch();
  delwin(newWindow);
  endwin();
  //wattron(newWindow, COLOR_PAIR(1));
}

// void Render::updateScreen() {
//   int row = 21;
//   int col = 21;
//   for (int i = 0; i < row; i++) {
//     for (int j = 0; j < col; j++){
//       char c = map.getMapData(i, j);
//       if (c == WALL || c == IMMUNEWALL) {
//         mvwprintw(newWindow, row, col*2, "\u25A1");
//       }
//       else if (c == EMPTY) {
//         mvwprintw(newWindow, row, col*2, "\u0020");
//       }
//       else if (c == SNAKE) {
//         mvwprintw(newWindow, row, col*2, "\u25CB");
//       }
//     }
//   }
//   wrefresh(newWindow);
// }
//
// void Render::endWindow() {
//   delwin(newWindow);
// }
