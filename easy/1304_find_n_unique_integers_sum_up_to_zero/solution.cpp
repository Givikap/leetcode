#include <vector>

class Solution {
public:
  std::vector<int> sumZero(int n) {
    std::vector<int> nums;
    nums.reserve(n);

    if (n % 2 == 1) {
      nums.push_back(0);
      --n;
    }

    for (int num = 1; num < n / 2 + 1; ++num) {
      nums.push_back(num);
      nums.push_back(-num);
    }

    return nums;
  }
};
