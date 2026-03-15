#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> numsSet;
    numsSet.reserve(nums.size());

    for (const int &num : nums) {
      if (!numsSet.insert(num).second)
        return true;
    }

    return false;
  }
};
