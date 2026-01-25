using namespace std;

#include <vector>

class Solution {
public:
  int specialArray(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    const int numsLen = nums.size();

    int i = 0;
    int x = numsLen;

    for (; i < numsLen && !nums[i]; ++i, --x)
      ;

    while (x) {
      if (nums[i] >= x)
        return x;
      else if (x - 1 == nums[i])
        break;

      ++i;
      --x;
    }

    return -1;
  }
};
