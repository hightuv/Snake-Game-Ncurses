#include "map.h"
#include <ncurses.h>

#define WALL '1'
#define IMMUNEWALL '2'
#define EMPTY '0'
#define SNAKE '3'

class Render {
  WINDOW *snakeWindow;
  Map map;
public:
  Render(char stage='1');
  void initUI();
  void updateUI();
  void endWindow();
};
