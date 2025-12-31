using namespace std;

#include <vector>

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    const int numsLen = nums.size();

    vector<int> sumsLeft = {0};
    vector<int> sumsRight(numsLen, 0);

    int i;

    for (i = 0; i < numsLen - 1; ++i)
      sumsLeft.push_back(sumsLeft[i] + nums[i]);

    for (i = numsLen - 2; i > -1; --i)
      sumsRight[i] = sumsRight[i + 1] + nums[i + 1];

    for (i = 0; i < numsLen; ++i) {
      if (sumsLeft[i] == sumsRight[i])
        return i;
    }

    return -1;
  }
};
