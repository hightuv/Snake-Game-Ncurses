#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>
#include "snakeMove.h"
#define WALL '1'
#define IMMUNEWALL '2'
#define EMPTY '0'
#define SNAKEHEAD '3'
#define SNAKEBODY '4'

class Render {
  char initMapDataArray[21][21];
  char mapDataArray[21][21];
  SnakeMove player;
  WINDOW *snakeWindow;
public:
  Render(char stage='1');
  void initUI();
  void updateUI();
  void endWindow();
  void setMap(int stage);
  char getMapData(int row, int col);
  void updateMapData();
};
