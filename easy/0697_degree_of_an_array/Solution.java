import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

class Solution {
  public int findShortestSubArray(int[] nums) {
    final Map<Integer, Integer> numsCounter = new HashMap<>();
    for (final int num : nums) {
      numsCounter.put(num, numsCounter.getOrDefault(num, 0) + 1);
    }

    final int maxCount = Collections.max(numsCounter.values());
    if (maxCount == 1) {
      return 1;
    }

    final int numsLen = nums.length;
    int minLen = numsLen;

    for (final Map.Entry<Integer, Integer> entry : numsCounter.entrySet()) {
      final Integer num = entry.getKey();
      final Integer count = entry.getValue();

      if (count == maxCount) {
        int left = 0;
        for (int i = 0; i < numsLen; ++i) {
          if (nums[i] == num) {
            left = i;
            break;
          }
        }

        int right = nums.length - 1;
        for (int i = right; i > -1; --i) {
          if (nums[i] == num) {
            right = i;
            break;
          }
        }

        minLen = Math.min(minLen, right - left + 1);
      }
    }

    return minLen;
  }
}
