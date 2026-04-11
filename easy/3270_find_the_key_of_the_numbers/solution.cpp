#include <algorithm>

class Solution {
public:
  int generateKey(int num1, int num2, int num3) {
    int key = 0;

    for (int div = 1000; div > 0; div /= 10) {
      key = key * 10 + std::min(num1 / div, std::min(num2 / div, num3 / div));

      num1 %= div;
      num2 %= div;
      num3 %= div;
    }

    return key;
  }
};
