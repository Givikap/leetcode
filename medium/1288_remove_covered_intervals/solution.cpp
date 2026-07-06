#include <vector>

class Solution {
public:
  int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const std::vector<int> &i1, const std::vector<int> &i2) {
           if (i1[0] == i2[0])
             return i1[1] > i2[1];
           return i1[0] < i2[0];
         });

    int uncoveredIntervalsCount = 0;
    int prevIntervalEnd = -1;

    for (const std::vector<int> &interval : intervals) {
      if (interval[1] > prevIntervalEnd) {
        ++uncoveredIntervalsCount;
        prevIntervalEnd = interval[1];
      }
    }

    return uncoveredIntervalsCount;
  }
};
