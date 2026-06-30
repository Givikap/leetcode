class Solution {
  public boolean isTrionic(int[] nums) {
    final int numsLen = nums.length;
    int i = 0;

    for (; i < numsLen - 1 && nums[i] < nums[i + 1]; ++i) {}
    if (i == 0 || i == numsLen - 1) {
      return false;
    }

    for (; i < numsLen - 1 && nums[i] > nums[i + 1]; ++i) {}
    if (i == numsLen - 1) {
      return false;
    }

    for (; i < numsLen - 1 && nums[i] < nums[i + 1]; ++i) {}
    return i == numsLen - 1;
  }
}
