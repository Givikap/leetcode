using namespace std;

#include <vector>

class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    const int numsLen = nums.size();

    vector<int> transformedNums(numsLen, 0);

    for (int i = 0; i < numsLen; ++i) {
      int ii = i + nums[i];
      while (ii < 0)
        ii += numsLen;

      transformedNums[i] = nums[ii % numsLen];
    }

    return transformedNums;
  }
};
