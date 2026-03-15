#include <algorithm>
#include <vector>

class Solution {
public:
  int minimumOperations(std::vector<int> &nums) {
    return count_if(nums.begin(), nums.end(),
                    [](int num) { return num % 3 != 0; });
  }
};
