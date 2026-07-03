import java.util.HashMap;
import java.util.Map;

class Solution {
  public int maximumLength(int[] nums) {
    final Map<Integer, Integer> numsCounter = new HashMap<>();
    for (final int num : nums) {
      numsCounter.put(num, numsCounter.getOrDefault(num, 0) + 1);
    }

    int maxLen = 0;
    if (numsCounter.containsKey(1)) {
      maxLen = numsCounter.remove(1);
      if (maxLen % 2 == 0) {
        --maxLen;
      }
    }

    for (final int num : numsCounter.keySet()) {
      int numCopy = num;
      int currLen = 0;

      while (numsCounter.getOrDefault(numCopy, 0) >= 2) {
        numCopy *= numCopy;
        currLen += 2;
      }

      if (numsCounter.getOrDefault(numCopy, 0) == 1) {
        maxLen = Math.max(maxLen, currLen + 1);
      } else {
        maxLen = Math.max(maxLen, currLen - 1);
      }
    }

    return maxLen;
  }
}
