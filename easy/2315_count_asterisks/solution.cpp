#include <string>

class Solution {
public:
  int countAsterisks(std::string s) {
    int asterisksCount = 0;
    bool inPair = false;

    for (const char &c : s) {
      if (c == '|')
        inPair = !inPair;
      else if (!inPair && c == '*')
        ++asterisksCount;
    }

    return asterisksCount;
  }
};
