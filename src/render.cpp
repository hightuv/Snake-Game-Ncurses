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
  time_t start = time(NULL);
  time_t end;
  int duration;

  // key input. default to right
  dir = KEY_RIGHT;
  while(true) {
    int in = dir;
    // key input
    if(keyInput()) {
      in = getch();
      if(in==dir)
        continue;
    }
    // opposit side input
    if((dir==KEY_RIGHT&&in==KEY_LEFT) || (dir==KEY_LEFT&&in==KEY_RIGHT) || (dir==KEY_UP&&in==KEY_DOWN) || (dir==KEY_DOWN&&in==KEY_UP))
      break;
    // direction set
    if(in==KEY_LEFT || in==KEY_RIGHT || in==KEY_UP || in==KEY_DOWN)
      dir = in;
    player.changePos(dir);
    // hit wall
    int head_row = player.getSnakeHeadPos(0);
    int head_col = player.getSnakeHeadPos(1);
    if(mapDataArray[head_row][head_col]==WALL || mapDataArray[head_row][head_col]==SNAKEBODY)
      break;
    end = time(NULL);
    duration = (int)(end - start);
    updateUI(duration);
    usleep(500000);
  }

  //delwin(snakeWindow);
  //endwin();
}

void Render::updateUI(int time) {
  updateMapData(time);
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
      else if (c == GROWTHITEM) {
        mvwprintw(snakeWindow, i, j*2, "ㄱ");
      }
      else if (c == POISONITEM) {
        mvwprintw(snakeWindow, i, j*2, "ㄴ");
      }
    }
  }
  wrefresh(snakeWindow);
}

void Render::updateMapData(int time) {
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
  if (time % 5 == 0) {
    spawnPoisonItem();
    spawnGrowthItem();
  }
  mapDataArray[poisonItem.first][poisonItem.second] = POISONITEM;
  mapDataArray[growthItem.first][growthItem.second] = GROWTHITEM;

}

void Render::spawnGrowthItem() {
  //time_t t = time(NULL);
  srand(time(NULL));
	int growth_x = rand() % 19 + 1;
	int growth_y = rand() % 19 + 1;
  while (mapDataArray[growth_x][growth_y] != EMPTY) {
    growth_x = rand() % 19 + 1;
  	growth_y = rand() % 19 + 1;
  }
  growthItem.first = growth_x;
  growthItem.second = growth_y;
}

void Render::spawnPoisonItem() {
  //time_t t = time(NULL);
  srand(time(NULL) + 1);
  int poison_x = rand() % 19 + 1;
	int poison_y = rand() % 19 + 1;
  while (mapDataArray[poison_x][poison_y] != EMPTY) {
    poison_x = rand() % 19 + 1;
  	poison_y = rand() % 19 + 1;
  }
  poisonItem.first = poison_x;
  poisonItem.second = poison_y;
}

bool Render::keyInput() {
  int ch;
  bool ret;

  nodelay(stdscr, TRUE);

  ch = getch();
  if(ch==ERR)
    ret = false;
  else {
    ret = true;
    ungetch(ch);
  }

  nodelay(stdscr, FALSE);
  return ret;
}
//
// void Render::endWindow() {
//   delwin(snakeWindow);
// }
