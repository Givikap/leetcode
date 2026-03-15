#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> sortByBits(std::vector<int> &arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      if (__builtin_popcount(a) == __builtin_popcount(b))
        return a < b;
      return __builtin_popcount(a) < __builtin_popcount(b);
    });
    return arr;
  }
};
