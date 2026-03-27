#include <vector>

class Solution {
public:
  int dominantIndices(std::vector<int> &nums) {
    int postfixSum = nums.back();
    int postfixCount = 1;

    int count = 0;

    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] * postfixCount > postfixSum)
        ++count;

      postfixSum += nums[i];
      ++postfixCount;
    }

    return count;
  }
};
