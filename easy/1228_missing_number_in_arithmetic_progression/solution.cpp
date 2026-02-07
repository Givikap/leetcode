using namespace std;

#include <vector>

class Solution {
public:
  int missingNumber(vector<int> &arr) {
    const int arrLen = arr.size();
    const int step = (arr[arrLen - 1] - arr[0]) / arrLen;

    if (step == 0)
      return arr[0];

    for (int i = 0, expected = arr[0]; expected != arr[arrLen - 1];
         ++i, expected += step) {
      if (arr[i] != expected)
        return expected;
    }

    return -1;
  }
};
