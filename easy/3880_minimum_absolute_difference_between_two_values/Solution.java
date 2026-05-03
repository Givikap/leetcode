class Solution {
  public int minAbsoluteDifference(int[] nums) {
    int minDifference = Integer.MAX_VALUE;

    int prevNum = 0;
    int prevI = 0;

    for (int i = 0; i < nums.length; ++i) {
      if (nums[i] == 0) {
        continue;
      }

      if (prevNum == 3 - nums[i] && i - prevI < minDifference) {
        minDifference = i - prevI;
      }

      prevNum = nums[i];
      prevI = i;
    }

    if (minDifference == Integer.MAX_VALUE) {
      return -1;
    } else {
      return minDifference;
    }
  }
}
