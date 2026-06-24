import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
  public int[] arrayRankTransform(int[] arr) {
    final int[] arrCopy = arr.clone();
    Arrays.sort(arrCopy);

    final Map<Integer, Integer> rankMap = new HashMap<>();

    int rank = 1;
    for (final int num : arrCopy) {
      if (!rankMap.containsKey(num)) {
        rankMap.put(num, rank);
        ++rank;
      }
    }

    for (int i = 0; i < arr.length; ++i) {
      arr[i] = rankMap.get(arr[i]);
    }

    return arr;
  }
}
