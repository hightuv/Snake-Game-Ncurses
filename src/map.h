#include <iostream>
#include <fstream>
#include <string>

class Map {
  char mapData[21][21];
  std::string mapFile = "../map/map";
public:
  Map(int stage=1);
  char getMapData(int row, int col);
};
