#include <vector>

class Solution {
public:
  std::vector<int> minBitwiseArray(std::vector<int> &nums) {
    std::vector<int> bitwiseArray;
    bitwiseArray.reserve(nums.size());

    for (const int &num : nums) {
      if (num & 1)
        bitwiseArray.push_back(num & ~(((num + 1) & ~num) >> 1));
      else
        bitwiseArray.push_back(-1);
    }

    return bitwiseArray;
  }
};
