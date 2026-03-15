#include <vector>

class Solution {
public:
  bool check(std::vector<int> &nums) {
    const int numsLen = nums.size();

    int i;
    for (i = 1; i < numsLen && nums[i - 1] <= nums[i]; ++i) {
    }

    if (i == numsLen)
      return true;

    for (; i < numsLen - 1; ++i)
      if (nums[i] > nums[i + 1])
        return false;

    return nums[0] >= nums[numsLen - 1];
  }
};
