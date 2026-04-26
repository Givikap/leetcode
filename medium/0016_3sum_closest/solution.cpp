#include <vector>

class Solution {
public:
  int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());

    int closestSum = INT16_MAX;
    int currSum;

    size_t left, mid, right;

    for (left = 0; left < nums.size() - 2; ++left) {
      mid = left + 1;
      right = nums.size() - 1;

      while (mid < right) {
        currSum = nums[left] + nums[mid] + nums[right];

        if (std::abs(target - currSum) < abs(target - closestSum))
          closestSum = currSum;

        if (currSum < target)
          ++mid;
        else if (currSum > target)
          --right;
        else
          return currSum;
      }
    }

    return closestSum;
  }
};
