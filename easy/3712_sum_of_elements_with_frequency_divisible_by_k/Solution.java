class Solution {
  public int sumDivisibleByK(int[] nums, int k) {
    final int[] numsCounter = new int[101];
    for (final int num : nums) {
      ++numsCounter[num];
    }

    int numsSum = 0;

    for (int i = 0; i < 101; ++i) {
      if (numsCounter[i] % k == 0) {
        numsSum += i * numsCounter[i];
      }
    }

    return numsSum;
  }
}
