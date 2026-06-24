import java.util.HashMap;
import java.util.Map;
import java.util.SortedSet;
import java.util.TreeSet;

class Solution {
  public int[] arrayRankTransform(int[] arr) {
    final SortedSet<Integer> arrSet = new TreeSet<>();
    for (final int num : arr) {
      arrSet.add(num);
    }

    final Map<Integer, Integer> rankMap = new HashMap<>();

    int rank = 0;
    for (final int num : arrSet) {
      rankMap.put(num, rank);
      ++rank;
    }

    for (int i = 0; i < arr.length; ++i) {
      arr[i] = rankMap.get(arr[i]);
    }

    return arr;
  }
}
