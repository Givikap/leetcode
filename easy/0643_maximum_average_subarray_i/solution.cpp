#include <numeric>
#include <vector>

class Solution {
public:
  double findMaxAverage(std::vector<int> &nums, int k) {
    int currSum = std::reduce(nums.begin(), nums.begin() + k);
    int maxSum = currSum;

    for (size_t i = k; i < nums.size(); ++i) {
      currSum = currSum + nums[i] - nums[i - k];
      maxSum = std::max(maxSum, currSum);
    }

    return (double)maxSum / k;
  }
};
