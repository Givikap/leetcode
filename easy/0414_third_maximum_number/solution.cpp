#include <vector>

class Solution {
public:
  int thirdMax(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int count = 1;
    for (size_t i = nums.size() - 1; i > 0; --i) {
      if (nums[i] != nums[i - 1]) {
        if (count == 2)
          return nums[i - 1];

        ++count;
      }
    }

    return nums.back();
  }
};
