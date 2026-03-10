using namespace std;

#include <set>

class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    const set<int> primeNumbersSet = {2, 3, 5, 7, 11, 13, 17, 19};

    int count = 0;

    for (int i = left; i < right + 1; ++i) {
      if (primeNumbersSet.find(__builtin_popcount(i)) != primeNumbersSet.end())
        ++count;
    }

    return count;
  }
};
