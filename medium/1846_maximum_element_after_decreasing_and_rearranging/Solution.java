class Solution {
  public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
    final int n = arr.length;
    final int[] numsCounter = new int[n];

    for (final int num : arr) {
      ++numsCounter[Math.min(num, n) - 1];
    }

    int maxElement = 1;
    for (int num = 2; num <= n; num++) {
      maxElement = Math.min(maxElement + numsCounter[num - 1], num);
    }

    return maxElement;
  }
}
