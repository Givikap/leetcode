#include <vector>

class Solution {
public:
  std::vector<int> concatWithReverse(std::vector<int> &nums) {
    for (size_t i = nums.size() - 1; i < -1; --i)
      nums.push_back(nums[i]);

    return nums;
  }
};
