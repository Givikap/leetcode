#include <vector>

class Solution {
public:
  int minTimeToVisitAllPoints(std::vector<std::vector<int>> &points) {
    int x1, y1, x2, y2;
    int time = 0;

    for (size_t i = 0; i < points.size() - 1; ++i) {
      x1 = points[i][0];
      y1 = points[i][1];
      x2 = points[i + 1][0];
      y2 = points[i + 1][1];

      time += std::max(abs(x1 - x2), abs(y1 - y2));
    }

    return time;
  }
};
