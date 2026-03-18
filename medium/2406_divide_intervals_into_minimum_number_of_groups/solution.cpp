#include <vector>

class Solution {
public:
  int minGroups(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end());

    std::vector<int> rooms;

    for (const std::vector<int> &interval : intervals) {
      if (!rooms.empty() && -rooms[0] < interval[0]) {
        std::pop_heap(rooms.begin(), rooms.end());
        rooms.pop_back();
      }

      rooms.push_back(-interval[1]);
      std::push_heap(rooms.begin(), rooms.end());
    }

    return rooms.size();
  }
};
