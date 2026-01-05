using namespace std;

#include <vector>

class Solution {
public:
  bool isMonotonic(vector<int> &nums) {
    const int numsLen = nums.size();

    if (numsLen == 1)
      return true;

    bool increasing = false;
    bool decreasing = false;

    for (int i = 1; i < numsLen; ++i) {
      if ((increasing && nums[i] < nums[i - 1]) ||
          (decreasing && nums[i] > nums[i - 1])) {
        return false;
      } else if (nums[i] > nums[i - 1]) {
        increasing = true;
      } else if (nums[i] < nums[i - 1]) {
        decreasing = true;
      }
    }

    return true;
  }
};
