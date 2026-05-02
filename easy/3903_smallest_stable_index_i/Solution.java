class Solution {
  public int firstStableIndex(int[] nums, int k) {
    final int[] prefixMaxes = new int[nums.length];
    final int[] prefixMins = new int[nums.length];

    prefixMaxes[0] = nums[0];
    for (int i = 1; i < nums.length; ++i) {
      prefixMaxes[i] = Math.max(prefixMaxes[i - 1], nums[i]);
    }

    prefixMins[nums.length - 1] = nums[nums.length - 1];
    for (int i = nums.length - 2; i > -1; --i) {
      prefixMins[i] = Math.min(prefixMins[i + 1], nums[i]);
    }

    for (int i = 0; i < nums.length; ++i) {
      if (prefixMaxes[i] - prefixMins[i] <= k) {
        return i;
      }
    }

    return -1;
  }
}
