#include <cmath>
#include <vector>

class Solution {
public:
  std::vector<int> constructRectangle(int area) {
    for (int side = std::sqrt(area); side > 0; --side) {
      if (area % side == 0)
        return std::vector<int>{area / side, side};
    }

    return std::vector<int>{area, 1};
  }
};
