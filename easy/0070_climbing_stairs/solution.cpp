class Solution {
public:
  int climbStairs(int n) {
    if (n < 4)
      return n;

    int prev = 2, curr = 3;

    for (int _ = 0; _ < n - 3; ++_) {
      curr += prev;
      prev = curr - prev;
    }

    return curr;
  }
};
