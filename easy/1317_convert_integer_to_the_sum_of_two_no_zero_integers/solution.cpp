using namespace std;

#include <vector>

class Solution {
public:
  bool containsZero(int n) {
    while (n > 0) {
      if (n % 10 == 0)
        return true;
      n /= 10;
    }

    return false;
  }

  vector<int> getNoZeroIntegers(int n) {
    for (int a = 1, b = n - 1;; a++, b--) {
      if (!containsZero(a) && !containsZero(b))
        return {a, b};
    }

    return {};
  }
};
