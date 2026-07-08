#include <vector>

class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    int cumilativeXor = nums.size();

    for (int i = 0; i < nums.size(); ++i)
      cumilativeXor ^= i ^ nums[i];

    return cumilativeXor;
  }
};
