#include <vector>

class Solution {
public:
  std::vector<int> sortArrayByParity(std::vector<int> &nums) {
    int even = 0;

    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] % 2 == 0) {
        std::swap(nums[even], nums[i]);
        ++even;
      }
    }

    return nums;
  }
};
