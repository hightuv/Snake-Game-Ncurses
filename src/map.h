#include <iostream>
#include <fstream>
#include <string>

class Map {
  char mapData[21][21];
public:
  Map(char stage='1');
  char getMapData(int row, int col);
};
