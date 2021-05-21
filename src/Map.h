#include <iostream>
#include <fstream>
#include <string>

class Map {
  char mapData[21][21];
  int stage = 1;
  std::string mapFile = "./map/map/"
public:
  void setStage(int stage);
  char getMapData(int row, int col);
};
