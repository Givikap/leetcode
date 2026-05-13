#include <vector>

class Solution {
private:
  std::vector<int> fibCache = {0, 1};

public:
  int fib(int n) {
    if (n < 2)
      return n;
    if (n < fibCache.size())
      return fibCache[n];

    const int fibN = fib(n - 1) + fib(n - 2);
    fibCache.push_back(fibN);
    return fibN;
  }
};
