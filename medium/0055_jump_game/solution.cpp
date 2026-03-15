#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    int maxI = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (i > maxI)
        return false;
      maxI = std::max(maxI, i + nums[i]);
    }

    return true;
  }
};
