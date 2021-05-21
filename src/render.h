#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>

#define WALL '1'
#define IMMUNEWALL '2'
#define EMPTY '0'
#define SNAKE '3'

class Render {
  char initMapDataArray[21][21];
  WINDOW *snakeWindow;
public:
  Render(char stage='1');
  void initUI();
  void updateUI();
  void endWindow();
  void setMap(int stage);
  char getMapData(int row, int col);
};
