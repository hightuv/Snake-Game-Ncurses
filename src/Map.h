#include <iostream>
#include <fstream>
#include <string>

class Map {
  char mapData[30][30];
  int stage = 1;
  std::string mapFile = "./map/map/"
public:
  void setStage(int stage);
  char getMapData(int row, int col);
};
