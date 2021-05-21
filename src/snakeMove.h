#include <deque>

class SnakeMove {
  int snakeHead[2];
  std::deque<std::pair<int,int>> snakeBody;
public:
  SnakeMove() {
    snakeHead[0] = 10, snakeHead[1] = 10;
    snakeBody.push_back(std::pair<int,int>(10,9));
    snakeBody.push_back(std::pair<int,int>(10,8));
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
  int getBodyLength() {
    return snakeBody.size();
  }
};