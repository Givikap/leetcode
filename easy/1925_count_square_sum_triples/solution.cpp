using namespace std;

#include <cmath>

class Solution {
public:
  int countTriples(int n) {
    int triplesCount = 0;
    double c;

    for (int a = 1; a <= n; ++a) {
      for (int b = 1; b <= n; ++b) {
        c = sqrt(a * a + b * b);

        if (c == (int)c && c <= n)
          triplesCount++;
      }
    }

    return triplesCount;
  }
};
