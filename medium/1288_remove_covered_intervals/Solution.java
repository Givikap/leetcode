import java.util.Arrays;

class Solution {
  public int removeCoveredIntervals(int[][] intervals) {
    Arrays.sort(
        intervals,
        (i1, i2) -> {
          final int compare = Integer.compare(i1[0], i2[0]);
          if (compare != 0) {
            return compare;
          }
          return Integer.compare(-i1[1], -i2[1]);
        });

    int uncoveredIntervalsCount = 0;
    int prevIntervalEnd = -1;

    for (final int[] interval : intervals) {
      if (interval[1] > prevIntervalEnd) {
        ++uncoveredIntervalsCount;
        prevIntervalEnd = interval[1];
      }
    }

    return uncoveredIntervalsCount;
  }
}
