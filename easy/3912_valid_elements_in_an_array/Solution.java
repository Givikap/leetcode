import java.util.ArrayList;
import java.util.List;

class Solution {
  public List<Integer> findValidElements(int[] nums) {
    final int numsLen = nums.length;

    final int[] prefixMaxes = new int[numsLen];
    final int[] suffixMaxes = new int[numsLen];

    for (int i = 1; i < numsLen; ++i) {
      prefixMaxes[i] = Math.max(prefixMaxes[i - 1], nums[i - 1]);
    }
    for (int i = numsLen - 2; i > -1; --i) {
      suffixMaxes[i] = Math.max(suffixMaxes[i + 1], nums[i + 1]);
    }

    final List<Integer> validNums = new ArrayList<>();
    validNums.add(nums[0]);

    for (int i = 1; i < numsLen - 1; ++i) {
      if (nums[i] > prefixMaxes[i] || nums[i] > suffixMaxes[i]) {
        validNums.add(nums[i]);
      }
    }

    if (numsLen != 1) {
      validNums.add(nums[numsLen - 1]);
    }

    return validNums;
  }
}
