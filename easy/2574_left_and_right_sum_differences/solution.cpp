#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<int> leftRightDifference(std::vector<int> &nums) {
    std::vector<int> differences;

    const int numsSum = std::reduce(nums.begin(), nums.end());
    int leftSum = 0;

    for (const int &num : nums) {
      differences.push_back(abs(leftSum * 2 + num - numsSum));
      leftSum += num;
    }

    return differences;
  }
};
