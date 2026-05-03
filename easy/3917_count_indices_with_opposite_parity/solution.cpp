#include <vector>

class Solution {
public:
  std::vector<int> countOppositeParity(std::vector<int> &nums) {
    std::vector<int> parities(nums.size(), 0);

    int even = 0;
    int odd = 0;

    for (int i = nums.size() - 1; i > -1; --i) {
      if (nums[i] % 2 == 0) {
        parities[i] = odd;
        ++even;
      } else {
        parities[i] = even;
        ++odd;
      }
    }

    return parities;
  }
};
