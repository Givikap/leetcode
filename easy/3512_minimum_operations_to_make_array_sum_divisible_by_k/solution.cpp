#include <numeric>
#include <vector>

class Solution {
public:
  int minOperations(std::vector<int> &nums, int k) {
    return reduce(nums.begin(), nums.end(), 0) % k;
  }
};
