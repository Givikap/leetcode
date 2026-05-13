class Solution {
  public int fib(int n) {
    if (n < 2) {
      return n;
    }

    int lastLast = 0;
    int last = 1;
    int fibN = 0;

    for (int i = 2; i < n + 1; ++i) {
      fibN = lastLast + last;
      lastLast = last;
      last = fibN;
    }

    return fibN;
  }
}
