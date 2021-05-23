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
  updateUI();
  wrefresh(snakeWindow);

  // key input. default to right
  int ch = KEY_RIGHT;
  while(true) {
    // 아무것도 입력되지 않으면 가던방향으로 감
    halfdelay(3);
    int in = getch();
    // opposit side input
    if((ch==KEY_RIGHT&&in==KEY_LEFT) || (ch==KEY_LEFT&&in==KEY_RIGHT) || (ch==KEY_UP&&in==KEY_DOWN) || (ch==KEY_DOWN&&in==KEY_UP))
      break;
    if(in!=-1)
      ch = in;
    player.changePos(ch);
    if(mapDataArray[player.getSnakeHeadPos(0)][player.getSnakeHeadPos(1)]==WALL)
      break;
    updateUI();
  }

  //delwin(snakeWindow);
  //endwin();
}

void Render::updateUI() {
  updateMapData();
  for(int i=0; i<ROW; i++) {
    for(int j=0; j<COL*2; j++) {
      mvwprintw(snakeWindow, i, j, " ");
    }
  }
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++){
      char c = mapDataArray[i][j];
      if (c == WALL || c == IMMUNEWALL) {
        mvwprintw(snakeWindow, i, j*2, "\u25A1");
      }
      else if (c == EMPTY) {
        mvwprintw(snakeWindow, i, j*2, "\u0020");
      }
      else if (c == SNAKEHEAD) {
        mvwprintw(snakeWindow, i, j*2, "ㅎ");
      }
      else if (c == SNAKEBODY) {
        mvwprintw(snakeWindow, i, j*2, "ㅇ");
      }
    }
  }
  wrefresh(snakeWindow);
}

void Render::updateMapData() {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++){
      char c = initMapDataArray[i][j];
      mapDataArray[i][j] = c;
    }
  }
  mapDataArray[player.getSnakeHeadPos(0)][player.getSnakeHeadPos(1)] = SNAKEHEAD;
  for (int i = 0; i < player.getBodyLength(); i++) {
    int x = player.getSnakeBodyPos(i).first;
    int y = player.getSnakeBodyPos(i).second;
    mapDataArray[x][y] = SNAKEBODY;
  }
}

//
// void Render::endWindow() {
//   delwin(snakeWindow);
// }
