using namespace std;

#include <vector>

class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    const int numsLen = nums.size();

    vector<int> transformedNums(numsLen, 0);

    for (int i = 0; i < numsLen; ++i)
      transformedNums[i] = nums[((i + nums[i]) % numsLen + numsLen) % numsLen];

    return transformedNums;
  }
};
