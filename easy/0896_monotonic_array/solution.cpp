using namespace std;

#include <vector>

class Solution {
public:
  bool isMonotonic(vector<int> &nums) {
    const int numsLen = nums.size();

    if (numsLen == 1)
      return true;

    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < numsLen; ++i) {
      if (nums[i] < nums[i - 1])
        increasing = false;
      if (nums[i] > nums[i - 1])
        decreasing = false;

      if (!increasing && !decreasing)
        return false;
    }

    return true;
  }
};
