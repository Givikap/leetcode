#include <vector>

class Solution {
public:
  int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    int uncoveredIntervalsCount = 1;
    std::vector<int> prevInterval = intervals[0];

    for (size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= prevInterval[0] &&
          intervals[i][1] <= prevInterval[1]) {

      } else if (intervals[i][0] <= prevInterval[0] &&
                 intervals[i][1] >= prevInterval[1]) {
        prevInterval = intervals[i];
      } else {
        ++uncoveredIntervalsCount;
        prevInterval = intervals[i];
      }
    }

    return uncoveredIntervalsCount;
  }
};
