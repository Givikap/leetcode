#include <vector>

class Solution {
public:
  int minimumSwaps(std::vector<int> &nums) {
    size_t left = 0;
    size_t right = nums.size() - 1;

    int swaps = 0;

    while (true) {
      while (left < right && nums[left] != 0)
        ++left;

      while (left < right && nums[right] == 0)
        --right;

      if (left < right) {
        std::swap(nums[left++], nums[right--]);
        ++swaps;
      } else {
        break;
      }
    }

    return swaps;
  }
};
