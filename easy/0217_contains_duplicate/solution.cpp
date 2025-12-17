using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> numsSet;
    numsSet.reserve(nums.size());

    for (const int &num : nums) {
      if (!numsSet.insert(num).second)
        return true;
    }

    return false;
  }
};
