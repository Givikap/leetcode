#include <vector>

class Solution {
public:
  std::vector<int> applyOperations(std::vector<int> &nums) {
    const size_t numsLen = nums.size();

    std::vector<int> modifiedNums;
    modifiedNums.reserve(numsLen);

    int zeroCount = 0;

    for (size_t i = 0; i < numsLen; ++i) {
      if (nums[i] == 0)
        ++zeroCount;
      else if (i < numsLen - 1 && nums[i] == nums[i + 1]) {
        modifiedNums.push_back(nums[i++] * 2);
        ++zeroCount;
      } else
        modifiedNums.push_back(nums[i]);
    }

    for (int _ = 0; _ < zeroCount; ++_)
      modifiedNums.push_back(0);

    return modifiedNums;
  }
};
