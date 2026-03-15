#include <vector>

class Solution {
public:
  bool divideArray(std::vector<int> &nums) {
    const int numsLen = nums.size();

    if (numsLen % 2 == 1)
      return false;

    sort(nums.begin(), nums.end());

    int i = 0;
    while (i < numsLen) {
      if (nums[i] != nums[i + 1])
        return false;

      i += 2;
    }

    return true;
  }
};
