#include <string>

class Solution {
public:
  bool isAdjacentDiffAtMostTwo(std::string s) {
    for (size_t i = 1; i < s.size(); ++i) {
      if (abs(s[i - 1] - s[i]) > 2)
        return false;
    }

    return true;
  }
};
