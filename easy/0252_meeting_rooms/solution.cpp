#include "../../utils/cpp/interval.hpp"
#include <algorithm>
#include <vector>

class Solution {
public:
  bool canAttendMeetings(std::vector<utils::Interval> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const utils::Interval &a, const utils::Interval &b) {
                return a.start < b.start;
              });

    for (int i = 0; i + 1 < intervals.size(); ++i) {
      if (intervals[i].end > intervals[i + 1].start)
        return false;
    }

    return true;
  }
};
