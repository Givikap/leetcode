#include <vector>

class Solution {
public:
  bool isMiddleElementUnique(std::vector<int> &nums) {
    return std::count(nums.begin(), nums.end(), nums[nums.size() / 2]) == 1;
  }
};
