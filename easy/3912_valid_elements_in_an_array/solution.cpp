#include <vector>

class Solution {
public:
  std::vector<int> findValidElements(std::vector<int> &nums) {
    const size_t numsLen = nums.size();

    std::vector<int> prefixMaxes(numsLen, 0);
    std::vector<int> suffixMaxes(numsLen, 0);

    for (size_t i = 1, j = numsLen - 2; i < numsLen; ++i, --j) {
      prefixMaxes[i] = std::max(prefixMaxes[i - 1], nums[i - 1]);
      suffixMaxes[j] = std::max(suffixMaxes[j + 1], nums[j + 1]);
    }

    std::vector<int> validNums = {nums[0]};

    for (size_t i = 1; i < numsLen - 1; ++i) {
      if (nums[i] > prefixMaxes[i] || nums[i] > suffixMaxes[i])
        validNums.push_back(nums[i]);
    }

    if (numsLen != 1)
      validNums.push_back(nums.back());

    return validNums;
  }
};
