#include "map.h"
#include <ncurses.h>

#define WALL '1';
#define IMMUNEWALL '2';
#define EMPTY '0';
#define SNAKE '3';

class Render {
  WINDOW *newWindow;
  Map map;
public:
  Render(int stage=1);
  void updateScreen();
  void endWindow();
};
