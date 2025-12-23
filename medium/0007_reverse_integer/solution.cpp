using namespace std;

#include <climits>
#include <cmath>

class Solution {
public:
  int reverse(int x) {
    if (x == -2147483648)
      return 0;

    const int REVERSE_INT_MAX = INT_MAX / 10;

    const int sign = x < 0 ? -1 : 1;
    x = abs(x);

    int reversedX = 0;

    while (x) {
      if (reversedX > REVERSE_INT_MAX)
        return 0;

      reversedX = reversedX * 10 + x % 10;
      x /= 10;
    }

    return sign * reversedX;
  }
};
