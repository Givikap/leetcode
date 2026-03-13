#include "../../utils/cpp/interval.hpp"
#include <algorithm>
#include <vector>

class Solution {
public:
  int minMeetingRooms(std::vector<Interval> &intervals) {
    std::sort(
        intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) { return a.start < b.start; });

    std::vector<int> heap;

    int maxRooms = 0;

    for (const Interval &interval : intervals) {
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
