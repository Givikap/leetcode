#include <vector>

class Solution {
public:
  int arrayPairSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int pairSum = 0;
    for (size_t i = 0; i < nums.size(); i += 2)
      pairSum += nums[i];

    return pairSum;
  }
};
