#include "../../utils/cpp/interval.hpp"
#include <algorithm>
#include <vector>

class Solution {
public:
  int minMeetingRooms(std::vector<utils::Interval> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const utils::Interval &a, const utils::Interval &b) {
                return a.start < b.start;
              });

    std::vector<int> heap;

    int maxRooms = 0;

    for (const utils::Interval &interval : intervals) {
      if (!heap.empty() && interval.start >= -heap[0]) {
        std::pop_heap(heap.begin(), heap.end());
        heap.pop_back();
      }

      heap.push_back(-interval.end);
      std::push_heap(heap.begin(), heap.end());

      maxRooms = std::max(maxRooms, (int)heap.size());
    }

    return maxRooms;
  }
};
