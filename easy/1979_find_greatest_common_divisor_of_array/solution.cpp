#include <numeric>
#include <vector>

class Solution {
public:
  int findGCD(std::vector<int> &nums) {
    int minNum = nums[0];
    int maxNum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
      minNum = std::min(minNum, nums[i]);
      maxNum = std::max(maxNum, nums[i]);
    }

    return std::gcd(minNum, maxNum);
  }
};
