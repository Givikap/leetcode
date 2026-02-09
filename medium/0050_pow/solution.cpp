using namespace std;

#include <stdlib.h>

class Solution {
public:
  double myPow(double x, int n) {
    if (x == 0)
      return 0;
    if (n == 0)
      return 1;
    if (n == 1)
      return x;

    long N = abs((long)n);

    double result = myPow(x, N / 2);
    result *= result;

    if (N % 2 == 1)
      result *= x;

    if (n < 0)
      result = 1 / result;

    return result;
  }
};
