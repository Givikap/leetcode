#include <vector>

class Solution {
public:
  std::vector<int> limitOccurrences(std::vector<int> &nums, int k) {
    std::vector<int> limitedNums = {nums[0]};

    int count = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
      if (limitedNums.back() == nums[i]) {
        if (count == k)
          continue;

        ++count;
      } else
        count = 1;

      limitedNums.push_back(nums[i]);
    }

    return limitedNums;
  }
};
