class Solution {
  public int[] sumZero(int n) {
    final int[] nums = new int[n];

    int i = 0;

    if (n % 2 == 1) {
      nums[i] = 0;
      ++i;
    }

    for (int num = 1; num < n / 2 + 1; ++num) {
      nums[i] = num;
      nums[i + 1] = -num;
      i += 2;
    }

    return nums;
  }
}
