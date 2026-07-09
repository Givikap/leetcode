#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int currSum = 0;
    int maxSum = INT32_MIN;

    for (const int &num : nums) {
      currSum += num;
      maxSum = std::max(maxSum, currSum);

      if (currSum < 0)
        currSum = 0;
    }

    return maxSum;
  }
};
