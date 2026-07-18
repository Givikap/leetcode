#include <vector>

class Solution {
public:
  int countMajoritySubarrays(std::vector<int> &nums, int target) {
    const size_t n = nums.size();

    int count = 0;

    for (size_t i = 0; i < n; ++i) {
      int targetCount = 0;

      for (size_t j = i; j < n; ++j) {
        if (nums[j] == target)
          ++targetCount;
        else
          --targetCount;

        if (targetCount > 0)
          ++count;
      }
    }

    return count;
  }
};
