class Solution {
  public boolean checkPerfectNumber(int num) {
    if (num < 2) {
      return false;
    }

    int divisorsSum = 0;

    for (int i = 1; i < (int) Math.sqrt(num) + 1; ++i) {
      if (num % i == 0) {
        divisorsSum += i + num / i;
      }
    }

    return divisorsSum - num == num;
  }
}
