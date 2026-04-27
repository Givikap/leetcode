#include <vector>

class Solution {
public:
  int maximumProduct(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    const size_t n = nums.size();
    return std::max(nums[n - 3] * nums[n - 2] * nums[n - 1],
                    nums[0] * nums[1] * nums[n - 1]);
  }
};
