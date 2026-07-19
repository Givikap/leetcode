#include <vector>

class Solution {
public:
  bool canReach(std::vector<int> &start, std::vector<int> &target) {
    return abs(target[0] - start[0]) % 2 == abs(target[1] - start[1]) % 2;
  }
};
