#include <iostream>
#include <fstream>
#include <string>

class Map {
  char mapData[30][30];
  std::string mapFile;
public:
  Map();
  char getMapData(int row, int col);
};
