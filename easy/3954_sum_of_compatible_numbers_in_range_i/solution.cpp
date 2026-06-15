#include <cmath>

class Solution {
public:
  int sumOfGoodIntegers(int n, int k) {
    int compatibleNumsSum = 0;

    for (int x = 1; x < n + k + 1; ++x) {
      if (abs(n - x) <= k && (n & x) == 0)
        compatibleNumsSum += x;
    }

    return compatibleNumsSum;
  }
};
