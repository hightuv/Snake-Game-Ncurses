#include <iostream>
#include <fstream>

class Map {
  char mapData[30][30];
public:
  Map();
  char getMapData(int row, int col);
}