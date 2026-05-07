import java.util.Map;
import java.util.TreeMap;

class Solution {
  public int[] minDistinctFreqPair(int[] nums) {
    final Map<Integer, Integer> numsCounter = new TreeMap<>();
    for (final int num : nums) {
      numsCounter.put(num, numsCounter.getOrDefault(num, 0) + 1);
    }

    final Integer[] values = numsCounter.keySet().toArray(Integer[]::new);

    for (int i = 0; i < values.length; i++) {
      for (int j = i + 1; j < values.length; j++) {
        final int x = values[i];
        final int y = values[j];

        if (!numsCounter.get(x).equals(numsCounter.get(y))) {
          return new int[] {x, y};
        }
      }
    }

    return new int[] {-1, -1};
  }
}
