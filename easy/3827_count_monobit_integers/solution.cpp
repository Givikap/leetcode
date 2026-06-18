#include <cmath>

class Solution {
public:
  int countMonobit(int n) {
    return static_cast<int>(std::floor(std::log2(n + 1) + 1));
  }
};
