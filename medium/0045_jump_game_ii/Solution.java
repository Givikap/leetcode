class Solution {
  public int jump(int[] nums) {
    final int n = nums.length;

    int currI = 0;
    int maxI = 0;

    int jumps = 0;

    for (int i = 0; i < n - 1; ++i) {
      maxI = Math.max(maxI, i + nums[i]);

      if (i == currI) {
        currI = maxI;
        ++jumps;
      }
    }

    return jumps;
  }
}
