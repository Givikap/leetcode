class Solution {
  public long sumAndMultiply(int n) {
    int nCopy = n;

    long nNew = 0;
    int mul = 1;
    int digitsSum = 0;

    while (nCopy != 0) {
      final int digit = nCopy % 10;
      nCopy /= 10;

      if (digit != 0) {
        nNew = digit * mul + nNew;
        mul *= 10;
        digitsSum += digit;
      }
    }

    return nNew * digitsSum;
  }
}
