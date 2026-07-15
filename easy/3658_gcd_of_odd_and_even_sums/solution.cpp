#include <numeric>

class Solution {
public:
  int gcdOfOddEvenSums(int n) {
    int sumOdd = 0;
    for (int num = 1; num < n * 2; num += 2)
      sumOdd += num;

    int sumEven = 0;
    for (int num = 2; num <= n * 2; num += 2)
      sumEven += num;

    return std::gcd(sumOdd, sumEven);
  }
};
