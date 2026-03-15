#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;

    int maxArea = 0;

    while (left < right) {
      maxArea = std::max(maxArea, std::min(height[left], height[right]) *
                                      (right - left));

      if (height[left] > height[right])
        --right;
      else
        ++left;
    }

    return maxArea;
  }
};
