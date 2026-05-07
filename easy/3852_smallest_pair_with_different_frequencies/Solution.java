import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

class Solution {
  public int[] minDistinctFreqPair(int[] nums) {
    final Map<Integer, Integer> numsCounter = new TreeMap<>();
    for (final int num : nums) {
      numsCounter.put(num, numsCounter.getOrDefault(num, 0) + 1);
    }

    final Iterator<Map.Entry<Integer, Integer>> iterator = numsCounter.entrySet().iterator();

    if (!iterator.hasNext()) {
      return new int[] {-1, -1};
    }

    final Map.Entry<Integer, Integer> smallest = iterator.next();

    final int x = smallest.getKey();
    final int xFrequency = smallest.getValue();

    while (iterator.hasNext()) {
      final Map.Entry<Integer, Integer> next = iterator.next();

      if (next.getValue() != xFrequency) {
        return new int[] {x, next.getKey()};
      }
    }

    return new int[] {-1, -1};
  }
}
