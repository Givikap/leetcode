#include <vector>

class Solution {
public:
  int firstStableIndex(std::vector<int> &nums, int k) {
    const int numsLen = nums.size();

    std::vector<int> prefixMaxes(numsLen, nums[0]);
    std::vector<int> prefixMins(numsLen, nums[numsLen - 1]);

    for (int i = 1; i < numsLen; ++i)
      prefixMaxes[i] = std::max(prefixMaxes[i - 1], nums[i]);

    for (int i = numsLen - 2; i > -1; --i)
      prefixMins[i] = std::min(prefixMins[i + 1], nums[i]);

    for (int i = 0; i < numsLen; ++i) {
      if (prefixMaxes[i] - prefixMins[i] <= k)
        return i;
    }

    return -1;
  }
};
