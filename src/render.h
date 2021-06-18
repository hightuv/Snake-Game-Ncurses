#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>
#include "snakeMove.h"
// random
#include <cstdlib>
// time sleep
#include <unistd.h>
#define EMPTY '0'
#define WALL '1'
#define IMMUNEWALL '2'
#define SNAKEHEAD '3'
#define SNAKEBODY '4'
#define GROWTHITEM '5'
#define POISONITEM '6'
#define GATE '7'
#define ROW 23
#define COL 23

class Render {
  char initMapDataArray[ROW][COL];
  char mapDataArray[ROW][COL];
  std::pair<int,int> growthItem;
  std::pair<int,int> poisonItem;
  std::pair<int,int> gate[2];
  SnakeMove player;
  int playerFutureMove[2];
  WINDOW *snakeWindow;
  WINDOW *scoreWindow;
  int dir = KEY_RIGHT;
  int growthCount = 0;
  int poisonCount = 0;
  int gateCount = 0;
  bool poison_hit = 0;
  bool growth_hit = 0;
  int passedBody = 0;
  bool gate_pass = 0;
  bool gate_spawn = 0;
  bool gameClear = false;
public:
  Render(char stage='1');
  void initUI();
  void updateUI(int time = 0);
  void endWindow();
  void setMap(int stage);
  char getMapData(int row, int col);
  void updateMapData(int time);
  void spawnGrowthItem();
  void spawnPoisonItem();
  void spawnGate();
  void getPlayerFutureMove(int dir);
  void changeDirAfterPassingGate();
  void checkGate();
  bool keyInput();
  void gameOver();
  void gameClearWindow();
  bool getGameClear();
};
