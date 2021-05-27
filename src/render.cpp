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
  snakeWindow = newwin(23, 46, 5, 10);
  start_color();
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  wbkgd(snakeWindow, COLOR_PAIR(2));
  updateUI();
  wrefresh(snakeWindow);
  time_t start = time(NULL);
  time_t end;
  int duration;

  // key input. default to right
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

    // hit items
    if (mapDataArray[head_row][head_col] == GROWTHITEM) {
      player.snakeHitGrowthItem();
      growth_hit = 1;
    }
    if (mapDataArray[head_row][head_col] == POISONITEM) {
      // body size less than 2
      if(!player.snakeHitPoisonItem())
        break;
      poison_hit = 1;
    }
    // hit Gate
    if (mapDataArray[head_row][head_col] == GATE) {
      if (gate[0].first == head_row && gate[0].second == head_col) {
        player.snakeHitGate(gate[1].first, gate[1].second);
      }
      else if (gate[1].first == head_row && gate[1].second == head_col) {
        player.snakeHitGate(gate[0].first, gate[0].second);
      }
      changeDirAfterPassingGate();
      gate_hit = 1;
    }

    end = time(NULL);
    duration = (int)(end - start);
    updateUI(duration);
    usleep(300000);
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
      if (c == WALL) {
        mvwprintw(snakeWindow, i, j*2, "\u25A1");
      }
      else if (c == IMMUNEWALL) {
        mvwprintw(snakeWindow, i, j*2, "\u0020");
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
      else if(c == GATE) {
        mvwprintw(snakeWindow, i, j*2, "ㅁ");
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
  if (time % 9 == 0) {
    spawnPoisonItem();
    spawnGrowthItem();
    spawnGate();
  }
  // items
  mapDataArray[poisonItem.first][poisonItem.second] = POISONITEM;
  mapDataArray[growthItem.first][growthItem.second] = GROWTHITEM;
  // gate
  mapDataArray[gate[0].first][gate[0].second] = GATE;
  mapDataArray[gate[1].first][gate[1].second] = GATE;

  if (poison_hit == 1) {
    mapDataArray[poisonItem.first][poisonItem.second] = EMPTY;
  }
  if (growth_hit == 1) {
    mapDataArray[growthItem.first][growthItem.second] = EMPTY;
  }
  mapDataArray[player.getSnakeHeadPos(0)][player.getSnakeHeadPos(1)] = SNAKEHEAD;
  for (int i = 0; i < player.getBodyLength(); i++) {
    int x = player.getSnakeBodyPos(i).first;
    int y = player.getSnakeBodyPos(i).second;
    mapDataArray[x][y] = SNAKEBODY;
  }
}

void Render::spawnGrowthItem() {
  growth_hit = 0;
  //time_t t = time(NULL);
  srand(time(NULL));
	int growth_x = rand() % 21 + 1;
	int growth_y = rand() % 21 + 1;
  while (mapDataArray[growth_x][growth_y] != EMPTY) {
    growth_x = rand() % 21 + 1;
  	growth_y = rand() % 21 + 1;
  }
  growthItem.first = growth_x;
  growthItem.second = growth_y;
}

void Render::spawnPoisonItem() {
  poison_hit = 0;
  //time_t t = time(NULL);
  srand(time(NULL) + 1);
  int poison_x = rand() % 21 + 1;
	int poison_y = rand() % 21 + 1;
  while (mapDataArray[poison_x][poison_y] != EMPTY) {
    poison_x = rand() % 21 + 1;
  	poison_y = rand() % 21 + 1;
  }
  poisonItem.first = poison_x;
  poisonItem.second = poison_y;
}

void Render::spawnGate() {
  //time_t t = time(NULL);
  srand(time(NULL));
  while(true) {
    int row1 = rand() % 23;
    int col1 = rand() % 23;
    int row2 = rand() % 23;
    int col2 = rand() % 23;
    if(mapDataArray[row1][col1] == WALL && mapDataArray[row2][col2] == WALL) {
      gate[0].first = row1;
      gate[0].second = col1;
      gate[1].first = row2;
      gate[1].second = col2;
      break;
    }
  }
}

void Render::changeDirAfterPassingGate() {
  
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
