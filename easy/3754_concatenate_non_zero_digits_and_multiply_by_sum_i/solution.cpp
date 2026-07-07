class Solution {
public:
  long long sumAndMultiply(int n) {
    long long nNew = 0;
    int mul = 1;
    int digitsSum = 0;

    while (n) {
      int digit = n % 10;
      n /= 10;

      if (digit != 0) {
        nNew = digit * mul + nNew;
        mul *= 10;
        digitsSum += digit;
      }
    }

    return nNew * digitsSum;
  }
};
