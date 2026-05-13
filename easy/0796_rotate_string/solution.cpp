#include <string>

class Solution {
public:
  bool rotateString(std::string s, std::string goal) {
    if (s.size() != goal.size())
      return false;

    for (size_t start = 0; start < s.size(); ++start) {
      if (s[start] == goal[0]) {
        if (s.compare(start, s.size() - start, goal, 0, s.size() - start) ==
                0 &&
            s.compare(0, start, goal, s.size() - start, start) == 0)
          return true;
      }
    }

    return false;
  }
};
