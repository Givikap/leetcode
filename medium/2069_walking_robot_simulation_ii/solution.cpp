#include <string>
#include <vector>

class Robot {
private:
  int width, height;
  int perimeter;

  int x = 0;
  int y = 0;

  int direction = 0;
  const std::string directions[4] = {"East", "North", "West", "South"};

public:
  Robot(int width, int height) : width(width), height(height) {
    this->perimeter = 2 * (width + height) - 4;
  }

  void step(int num) {
    if (this->perimeter == 0)
      return;

    num %= this->perimeter;
    if (num == 0)
      num = this->perimeter;

    int distance;

    while (num > 0) {
      if (this->direction == 0) {
        distance = (this->width - 1) - this->x;
        if (num <= distance) {
          this->x += num;
          return;
        }
        this->x = this->width - 1;
      } else if (this->direction == 1) {
        distance = (this->height - 1) - this->y;
        if (num <= distance) {
          this->y += num;
          return;
        }
        this->y = this->height - 1;
      } else if (this->direction == 2) {
        distance = this->x;
        if (num <= distance) {
          this->x -= num;
          return;
        }
        this->x = 0;
      } else {
        distance = this->y;
        if (num <= distance) {
          this->y -= num;
          return;
        }
        this->y = 0;
      }

      num -= distance;
      this->direction = (this->direction + 1) % 4;
    }
  }

  std::vector<int> getPos() { return std::vector<int>{this->x, this->y}; }

  std::string getDir() { return this->directions[this->direction]; }
};
