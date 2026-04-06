#include <set>
#include <vector>

class Solution {
public:
  int robotSim(std::vector<int> &commands,
               std::vector<std::vector<int>> &obstacles) {
    std::set<std::pair<int, int>> obstaclesSet;
    for (const std::vector<int> &obstacle : obstacles)
      obstaclesSet.insert(std::pair<int, int>{obstacle[0], obstacle[1]});

    int x = 0, y = 0;
    int direction = 0;

    int maxDistance = 0;

    for (const int &command : commands) {
      if (command == -1)
        direction += 90;
      else if (command == -2)
        direction -= 90;
      else {
        direction = ((direction % 360) + 360) % 360;
        int dx = 0, dy = 0;

        if (direction == 0)
          dy = 1;
        else if (direction == 90)
          dx = 1;
        else if (direction == 180)
          dy = -1;
        else if (direction == 270)
          dx = -1;

        for (int _ = 0; _ < command; ++_) {
          if (obstaclesSet.find(std::pair<int, int>{x + dx, y + dy}) !=
              obstaclesSet.end())
            break;

          x += dx;
          y += dy;
        }

        maxDistance = std::max(maxDistance, x * x + y * y);
      }
    }

    return maxDistance;
  }
};
