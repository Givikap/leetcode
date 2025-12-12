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
    int a = 1;
    int b = n - 1;

    while (containsZero(a) || containsZero(b)) {
      ++a;
      --b;
    }

    return {a, b};
  }
};
