using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> targetsMap;
    int i, otherNum;

    for (i = 0; i < nums.size(); i++) {
      otherNum = target - nums[i];

      if (targetsMap.find(otherNum) != targetsMap.end())
        break;
      else
        targetsMap[nums[i]] = i;
    }

    return {targetsMap[otherNum], i};
  }
};
