#include <vector>

class Solution {
public:
  int minimumDifference(std::vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int minDiff = 100000;

    for (int i = 0; i < nums.size() - k + 1; ++i)
      minDiff = std::min(minDiff, nums[i + k - 1] - nums[i]);

    return minDiff;
  }
};
