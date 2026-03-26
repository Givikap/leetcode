#include <vector>

class Solution {
public:
  std::vector<int> constructTransformedArray(std::vector<int> &nums) {
    const size_t numsLen = nums.size();

    std::vector<int> transformedNums(numsLen, 0);

    for (size_t i = 0; i < numsLen; ++i) {
      int ii = i + nums[i];
      while (ii < 0)
        ii += numsLen;

      transformedNums[i] = nums[ii % numsLen];
    }

    return transformedNums;
  }
};
