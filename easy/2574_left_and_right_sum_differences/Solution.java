import java.util.Arrays;

class Solution {
  public int[] leftRightDifference(int[] nums) {
    final int[] differences = new int[nums.length];

    final int numsSum = Arrays.stream(nums).sum();
    int leftSum = 0;

    for (int i = 0; i < nums.length; ++i) {
      differences[i] = Math.abs(leftSum * 2 + nums[i] - numsSum);
      leftSum += nums[i];
    }

    return differences;
  }
}
