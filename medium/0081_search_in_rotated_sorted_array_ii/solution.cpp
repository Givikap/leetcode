#include <vector>

class Solution {
public:
  bool search(std::vector<int> &nums, int target) {
    size_t left = 0;
    size_t right = nums.size() - 1;

    while (left <= right) {
      size_t mid = left + (right - left) / 2;

      if (nums[mid] == target)
        return true;

      while (left < right && nums[left] == nums[mid] &&
             nums[mid] == nums[right]) {
        ++left;
        --right;
      }

      if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && target < nums[mid])
          right = mid - 1;
        else
          left = mid + 1;
      } else {
        if (nums[mid] < target && target <= nums[right])
          left = mid + 1;
        else
          right = mid - 1;
      }
    }

    return false;
  }
};
