#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>
#include "snakeMove.h"
// pair
#include <utility>
// random
#include <cstdlib>
// time
#include <ctime>
// time sleep
#include <unistd.h>
#define EMPTY '0'
#define WALL '1'
#define IMMUNEWALL '2'
#define SNAKEHEAD '3'
#define SNAKEBODY '4'
#define GROWTHITEM '5'
#define POISONITEM '6'
#define ROW 21
#define COL 21

class Render {
  char initMapDataArray[21][21];
  char mapDataArray[21][21];
  std::pair<int,int> growthItem;
  std::pair<int,int> poisonItem;
  SnakeMove player;
  WINDOW *snakeWindow;
  char dir;
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
  bool keyInput();
};
