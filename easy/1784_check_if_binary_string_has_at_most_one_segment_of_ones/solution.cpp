#include <string>

class Solution {
public:
  bool checkOnesSegment(std::string s) {
    const int sLen = s.size();

    bool hasOnesSegment = false;

    for (int i = 0; i < sLen; ++i) {
      if (s[i] == '1') {
        if (hasOnesSegment)
          return false;
        hasOnesSegment = true;

        while (i + 1 < sLen && s[i + 1] == '1')
          ++i;
      }
    }

    return hasOnesSegment;
  }
};
