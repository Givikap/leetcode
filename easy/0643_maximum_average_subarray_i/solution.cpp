#include <numeric>
#include <vector>

class Solution {
public:
  double findMaxAverage(std::vector<int> &nums, int k) {
    int currSum = 0;
    for (size_t i = 0; i < static_cast<size_t>(k); ++i)
      currSum += nums[i];

    int maxSum = currSum;

    for (size_t i = static_cast<size_t>(k); i < nums.size(); ++i) {
      currSum += nums[i] - nums[i - static_cast<size_t>(k)];
      maxSum = std::max(maxSum, currSum);
    }

    return (double)maxSum / k;
  }
};
