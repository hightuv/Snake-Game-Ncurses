#include <deque>
#include <ncurses.h>

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
  int getSnakeHeadPos(int i) {
    return snakeHead[i];
  }
  std::pair<int,int> getSnakeBodyPos(int i) {
    return snakeBody[i];
  }
  void snakeHitGrowthItem(std::pair<int,int> growthItem) {
    snakeBody.push_back(tail);
  }
  void snakeHitPoisonItem(std::pair<int,int> poisonItem) {
    snakeBody.pop_back();
  }
  int getBodyLength() {
    return snakeBody.size();
  }
};
