#include <vector>

class Solution {
public:
  int maxWidthOfVerticalArea(std::vector<std::vector<int>> &points) {
    std::sort(points.begin(), points.end());

    int widestGap = 0;

    for (size_t i = 1; i < points.size(); ++i)
      widestGap = std::max(widestGap, points[i][0] - points[i - 1][0]);

    return widestGap;
  }
};
