#include <vector>

class Solution {
public:
  bool asteroidsDestroyed(int mass, std::vector<int> &asteroids) {
    std::sort(asteroids.begin(), asteroids.end());

    for (const auto &asteroid : asteroids) {
      if (mass >= asteroid)
        mass = std::min(100001, mass + asteroid);
      else
        return false;
    }

    return true;
  }
};
