#include <cmath>

class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num < 2)
      return false;

    int divisorsSum = 0;

    for (int i = 1; i < static_cast<int>(std::sqrt(num)) + 1; ++i) {
      if (num % i == 0)
        divisorsSum += i + num / i;
    }

    return divisorsSum - num == num;
  }
};
