#include <cmath>
#include <vector>

class Solution {
public:
  std::vector<int> constructRectangle(int area) {
    for (int side = std::sqrt(area); side > 0; --side) {
      if (area % side == 0)
        return {area / side, side};
    }

    return {area, 1};
  }
};
