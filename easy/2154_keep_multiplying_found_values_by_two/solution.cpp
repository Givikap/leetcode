using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  int findFinalValue(vector<int> &nums, int original) {
    unordered_set<int> numsSet(nums.begin(), nums.end());

    while (numsSet.find(original) != numsSet.end())
      original *= 2;

    return original;
  }
};
