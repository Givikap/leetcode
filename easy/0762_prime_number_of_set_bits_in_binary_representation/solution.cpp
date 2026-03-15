#include <set>

class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    int count = 0;

    for (int i = left; i < right + 1; ++i) {
      int bitsCount = __builtin_popcount(i);

      if (bitsCount == 2 || bitsCount == 3 ||
          (bitsCount != 1 && bitsCount % 2 != 0 && bitsCount % 3 != 0))
        ++count;
    }

    return count;
  }
};
