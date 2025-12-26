using namespace std;

#include <vector>

class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> runningSums;
    int currSum = 0;

    for (const int &num : nums) {
      currSum += num;
      runningSums.push_back(currSum);
    }

    return runningSums;
  }
};
