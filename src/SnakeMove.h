#include <deque>

class SnakeMove {
  int snakeHead[2];
  std::deque<std::pair<int,int>> snakeBody;
public:
  SnakeMove() {
    snakeHead[0] = 5, snakeHead[1] = 5;
    snakeBody.push_back(std::pair<int,int>(5,4));
    snakeBody.push_back(std::pair<int,int>(5,3));
  }
  void changePos (int keyPressed) {
    if (keyPressed == 72) { // Up
      snakeBody.pop_back();
      snakeBody.push_front(std::pair<int,int>(snakeHead[0],snakeHead[1]));
      snakeHead[0] -= 1;
    }
    else if (keyPressed == 80) { // Down
      snakeBody.pop_back();
      snakeBody.push_front(std::pair<int,int>(snakeHead[0],snakeHead[1]));
      snakeHead[0] += 1;
    }
    else if (keyPressed == 75) { // Left
      snakeBody.pop_back();
      snakeBody.push_front(std::pair<int,int>(snakeHead[0],snakeHead[1]));
      snakeHead[1] -= 1;
    }
    else if (keyPressed == 77) { // Right
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
};
