#include "Map.h"
#include <ncurses.h>

#define WALL '1';
#define IMMUNEWALL '2';
#define EMPTY '0';
#define SNAKE '3';

class Render {
  WINDOW *newWindow;
  Map map;
public:
  Render();
  void updateScreen();
  void endWindow();
};
