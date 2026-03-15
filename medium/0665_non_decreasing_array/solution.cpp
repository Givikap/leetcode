#include <vector>

class Solution {
public:
  bool checkPossibility(std::vector<int> &nums) {
    bool modified = false;

    for (int i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i] > nums[i + 1]) {
        if (modified)
          return false;
        else
          modified = true;

        if (i > 0 && nums[i - 1] > nums[i + 1])
          nums[i + 1] = nums[i];
        else
          nums[i] = nums[i + 1];
      }
    }

    return true;
  }
};
