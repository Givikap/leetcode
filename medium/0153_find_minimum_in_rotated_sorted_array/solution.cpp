#include <vector>

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    size_t left = 0;
    size_t right = nums.size() - 1;

    while (left < right) {
      size_t mid = (left + right) / 2;

      if (nums[mid] > nums[right])
        left = mid + 1;
      else
        right = mid;
    }

    return nums[left];
  }
};
