#include <cmath>

class Solution {
public:
  int mirrorDistance(int n) {
    int nCopy = n;
    int reverseN = 0;

    while (nCopy) {
      reverseN = reverseN * 10 + nCopy % 10;
      nCopy /= 10;
    }

    return std::abs(n - reverseN);
  }
};
