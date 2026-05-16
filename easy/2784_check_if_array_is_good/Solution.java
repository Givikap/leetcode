class Solution {
  public boolean isGood(int[] nums) {
    final int n = nums.length;
    final int[] numsCounter = new int[n];

    for (int i = 0; i < n; ++i) {
      if (nums[i] >= n) {
        return false;
      }

      numsCounter[nums[i]]++;

      if (numsCounter[nums[i]] > 1 && nums[i] != n - 1) {
        return false;
      }
    }

    return numsCounter[n - 1] == 2;
  }
}
