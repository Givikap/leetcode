#include <vector>

class Solution {
public:
  std::vector<int> runningSum(std::vector<int> &nums) {
    std::vector<int> runningSums;
    int currSum = 0;

    for (const int &num : nums) {
      currSum += num;
      runningSums.push_back(currSum);
    }

    return runningSums;
  }
};
