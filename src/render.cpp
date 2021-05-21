#include "render.h"

Render::Render(char stage) {
  // game window
  setMap(stage);
  initUI();
}

void Render::setMap(int stage) {
  std::string mapFile = "../map/map" + std::to_string(stage-48) + ".txt"; // "../map/map" + stage + ".txt"
  std::ifstream fin(mapFile);
  try{
    if(!fin) throw;
  }
  catch(...) {
    std::cout << "file read failed." << std::endl;
  }

  int row = 0;
  int col = 0;
  int c;
  while((c = fin.get()) != EOF) {
    if (c == '\n') {
      row += 1;
      col = 0;
      continue;
    }
    else if (c != '0' && c != '1' && c != '2') {
      continue;
    }

    initMapDataArray[row][col] = (char)c;
    col += 1;
  }
  fin.close();
}

void Render::initUI() {
  snakeWindow = newwin(21, 42, 5, 10);
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
      char c = getMapData(i, j);
      if (c == WALL || c == IMMUNEWALL) {
        mvwprintw(snakeWindow, i, j*2, "\u25A1");
      }
      else if (c == EMPTY) {
        mvwprintw(snakeWindow, i, j*2, "\u0020");
      }
      else if (c == SNAKE) {
        mvwprintw(snakeWindow, i, j*2, "\u25CB");
      }
    }
  }
  wrefresh(snakeWindow);
}

char Render::getMapData(int row, int col) {
  return initMapDataArray[row][col];
}

//
// void Render::endWindow() {
//   delwin(snakeWindow);
// }
