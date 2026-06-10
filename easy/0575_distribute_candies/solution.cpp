#include <unordered_set>
#include <vector>

class Solution {
public:
  int distributeCandies(std::vector<int> &candyType) {
    return std::min(
        static_cast<int>(
            std::unordered_set<int>(candyType.begin(), candyType.end()).size()),
        static_cast<int>(candyType.size()) / 2);
  }
};
