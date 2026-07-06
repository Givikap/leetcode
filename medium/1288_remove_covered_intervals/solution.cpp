#include <vector>

class Solution {
public:
  int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const std::vector<int> &a, const std::vector<int> &b) {
           if (a[0] == b[0])
             return a[1] > b[1];
           return a[0] < b[0];
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
