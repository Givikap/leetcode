#include <vector>

class Solution {
public:
  bool isGood(std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<int> numsCounter(n, 0);

    for (int i = 0; i < n; ++i) {
      if (nums[i] >= n)
        return false;

      numsCounter[nums[i]]++;

      if (numsCounter[nums[i]] > 1 && nums[i] != n - 1)
        return false;
    }

    return numsCounter[n - 1] == 2;
  }
};
