using namespace std;

class Solution {
public:
  int numberOfMatches(int n) {
    int matchesCount = 0;

    while (n > 1) {
      matchesCount += n / 2;

      if (n % 2 == 1)
        ++n;

      n /= 2;
    }

    return matchesCount;
  }
};
