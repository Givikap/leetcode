using namespace std;

#include <vector>

class Solution {
public:
  int maxAscendingSum(vector<int> &nums) {
    const size_t numsLen = nums.size();

    int currSum = nums[0];
    int maxSum = 0;

    for (size_t i = 1; i < numsLen; ++i) {
      if (nums[i - 1] < nums[i]) {
        currSum += nums[i];
      } else {
        maxSum = max(currSum, maxSum);
        currSum = nums[i];
      }
    }

    return max(currSum, maxSum);
  }
};
