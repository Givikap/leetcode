#include <vector>

class Solution {
public:
  void rotate(std::vector<int> &nums, int k) {
    const int n = nums.size();
    k = k % n;

    for (auto &[left, right] :
         std::vector<std::pair<int, int>>{{0, n - 1}, {0, k - 1}, {k, n - 1}}) {
      while (left < right)
        std::swap(nums[left++], nums[right--]);
    }
  }
};
