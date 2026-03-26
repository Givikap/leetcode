#include <vector>

class Solution {
public:
  int heightChecker(std::vector<int> &heights) {
    std::vector<int> expectedHeights(heights.begin(), heights.end());
    sort(expectedHeights.begin(), expectedHeights.end());

    int mismatchedHeightsCount = 0;

    for (size_t i = 0; i < heights.size(); ++i) {
      if (heights[i] != expectedHeights[i])
        ++mismatchedHeightsCount;
    }

    return mismatchedHeightsCount;
  }
};
