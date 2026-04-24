#include <string>

class Solution {
public:
  int furthestDistanceFromOrigin(std::string moves) {
    int leftCount = 0, rightCount = 0, blankCount = 0;

    for (const char &move : moves) {
      if (move == 'L')
        ++leftCount;
      else if (move == 'R')
        ++rightCount;
      else
        ++blankCount;
    }

    return std::abs(leftCount - rightCount) + blankCount;
  }
};
