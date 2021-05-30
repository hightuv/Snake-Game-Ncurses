#include <deque>
#include <ncurses.h>
#include <algorithm>

class SnakeMove {
  int snakeHead[2];
  std::deque<std::pair<int,int>> snakeBody;
  std::pair<int,int> tail;
public:
  SnakeMove() {
    snakeHead[0] = 10, snakeHead[1] = 10;
    snakeBody.push_back(std::pair<int,int>(10,9));
    snakeBody.push_back(std::pair<int,int>(10,8));
  }
  SnakeMove(const SnakeMove& copy) {
    snakeHead[0] = copy.snakeHead[0]; snakeHead[1] = copy.snakeHead[1];
    std::copy(copy.snakeBody.begin(), copy.snakeBody.end(), snakeBody.begin());
  }
  void changePos (int keyPressed) {
    if (keyPressed == KEY_UP) { // Up
      tail = *(snakeBody.end() - 1);
      snakeBody.pop_back();
      snakeBody.push_front(std::pair<int,int>(snakeHead[0],snakeHead[1]));
      snakeHead[0] -= 1;
    }
    else if (keyPressed == KEY_DOWN) { // Down
      tail = *(snakeBody.end() - 1);
      snakeBody.pop_back();
      snakeBody.push_front(std::pair<int,int>(snakeHead[0],snakeHead[1]));
      snakeHead[0] += 1;
    }
    else if (keyPressed == KEY_LEFT) { // Left
      tail = *(snakeBody.end() - 1);
      snakeBody.pop_back();
      snakeBody.push_front(std::pair<int,int>(snakeHead[0],snakeHead[1]));
      snakeHead[1] -= 1;
    }
    else if (keyPressed == KEY_RIGHT) { // Right
      tail = *(snakeBody.end() - 1);
      snakeBody.pop_back();
      snakeBody.push_front(std::pair<int,int>(snakeHead[0],snakeHead[1]));
      snakeHead[1] += 1;
    }
  }
  void SnakeHeadPosOtherGate (int dir) {
    if (dir == KEY_UP) { // Up
      snakeHead[0] -= 1;
    }
    else if (dir == KEY_DOWN) { // Down
      snakeHead[0] += 1;
    }
    else if (dir == KEY_LEFT) { // Left
      snakeHead[1] -= 1;
    }
    else if (dir == KEY_RIGHT) { // Right
      snakeHead[1] += 1;
    }
  }
  int getSnakeHeadPos(int i) {
    return snakeHead[i];
  }
  std::pair<int,int> getSnakeBodyPos(int i) {
    return snakeBody[i];
  }
  void snakeHitGrowthItem() {
    snakeBody.push_back(tail);
  }
  bool snakeHitPoisonItem() {
    snakeBody.pop_back();
    if(snakeBody.size()<2)
      return false;
    return true;
  }
  void snakeHitGate(int otherGate_x, int otherGate_y) {
    snakeHead[0] = otherGate_x; snakeHead[1] = otherGate_y;
  }
  int getBodyLength() {
    return snakeBody.size();
  }
};
