#include <unordered_set>
#include <vector>

class Solution {
public:
  int repeatedNTimes(std::vector<int> &nums) {
    std::unordered_set<int> seen;

    for (const int &num : nums) {
      if (seen.find(num) != seen.end())
        return num;

      seen.insert(num);
    }

    return -1;
  }
};
