#include <iostream>
#include <fstream>

class Map {
  char mapData[30][30];
  int stage;
  const char* mapFile = "./map/map" + stage + ".txt";
public:
  Map();
  void chooseStage(int stage);
  char getStageMapData(int row, int col);
}
