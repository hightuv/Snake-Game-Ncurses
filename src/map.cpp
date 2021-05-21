#include "map.h"

Map::Map(char stage) {
  printf("%c", stage);
  std::string mapFile = "../map/" + std::to_string(stage-48) + ".txt"; // "../map/map" + stage + ".txt"
  std::ifstream fin(mapFile);
  // try{
  //   if(!fin) throw;
  // }
  // catch(...) {
  //   std::cout << "file read failed." << std::endl;
  // }

  int row = 0;
  int col = 0;
  int c;
  while((c = fin.get()) != EOF) {
    if (c == '\n') {
      row += 1;
      col = 0;
      continue;
    }
    else if (c != '0' && c != '1' && c != '2') {
      continue;
    }

    mapData[row][col] = (char)c;
    col += 1;
  }
  fin.close();
}

char Map::getMapData(int row, int col) {
  return mapData[row][col];
}
