import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

class Solution {
  public int findShortestSubArray(int[] nums) {
    final Map<Integer, Integer> numsCounter = new HashMap<>();
    final Map<Integer, Integer> firstMap = new HashMap<>();
    final Map<Integer, Integer> lastMap = new HashMap<>();

    for (int i = 0; i < nums.length; i++) {
      final int num = nums[i];

      numsCounter.put(num, numsCounter.getOrDefault(num, 0) + 1);

      if (!firstMap.containsKey(num)) {
        firstMap.put(num, i);
      }
      lastMap.put(num, i);
    }

    final int maxCount = Collections.max(numsCounter.values());
    if (maxCount == 1) {
      return 1;
    }

    int minLen = nums.length;

    for (final int num : numsCounter.keySet()) {
      if (numsCounter.get(num) == maxCount) {
        minLen = Math.min(minLen, lastMap.get(num) - firstMap.get(num) + 1);
      }
    }

    return minLen;
  }
}
