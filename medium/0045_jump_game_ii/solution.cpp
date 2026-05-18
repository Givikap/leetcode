#include <vector>

class Solution {
public:
  int jump(std::vector<int> &nums) {
    const int n = nums.size();

    int currI = 0, maxI = 0;
    int jumps = 0;

    for (int i = 0; i < n - 1; ++i) {
      maxI = std::max(maxI, i + nums[i]);

      if (i == currI) {
        currI = maxI;
        ++jumps;
      }
    }

    return jumps;
  }
};
