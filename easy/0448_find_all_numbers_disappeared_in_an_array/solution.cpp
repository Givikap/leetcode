#include <vector>

class Solution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
    for (const int &num : nums) {
      size_t i = abs(num) - 1;

      if (nums[i] > 0)
        nums[i] *= -1;
    }

    std::vector<int> disappearedNums;

    for (int i = 1; i <= nums.size(); ++i) {
      if (nums[i - 1] > 0)
        disappearedNums.push_back(i);
    }

    return disappearedNums;
  }
};
