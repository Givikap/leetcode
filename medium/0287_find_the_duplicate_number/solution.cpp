#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    for (const int &num : nums) {
      int absNum = abs(num);

      if (nums[absNum - 1] < 0)
        return absNum;

      nums[absNum - 1] *= -1;
    }

    return -1;
  }
};
