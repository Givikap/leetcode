class Solution {
  public boolean checkGoodInteger(int n) {
    int nCopy = n;

    int digitSum = 0;
    int squareSum = 1;

    while (nCopy != 0) {
      final int digit = nCopy % 10;
      nCopy /= 10;

      digitSum += digit;
      squareSum += digit * digit;
    }

    return squareSum - digitSum >= 50;
  }
}
