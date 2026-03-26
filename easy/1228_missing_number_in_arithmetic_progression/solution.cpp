#include <vector>

class Solution {
public:
  int missingNumber(std::vector<int> &arr) {
    const size_t arrLen = arr.size();
    const int step = (arr[arrLen - 1] - arr[0]) / arrLen;

    if (step == 0)
      return arr[0];

    for (size_t i = 0, expected = arr[0]; expected != arr[arrLen - 1];
         ++i, expected += step) {
      if (arr[i] != expected)
        return expected;
    }

    return -1;
  }
};
