#include <vector>

class Solution {
public:
  double largestTriangleArea(std::vector<std::vector<int>> &points) {
    double maxArea = 0.0;

    for (size_t i = 0; i < points.size(); ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        for (size_t k = j + 1; k < points.size(); ++k) {
          int x1 = points[i][0], y1 = points[i][1];
          int x2 = points[j][0], y2 = points[j][1];
          int x3 = points[k][0], y3 = points[k][1];

          maxArea = std::max(
              maxArea,
              std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
        }
      }
    }

    return maxArea;
  }
};
