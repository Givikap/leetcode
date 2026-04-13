#include <vector>

class Solution {
public:
  int getMinDistance(std::vector<int> &nums, int target, int start) {
    int minDist = INT32_MAX;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target)
        minDist = std::min(minDist, std::abs(i - start));
    }

    return minDist;
  }
};
