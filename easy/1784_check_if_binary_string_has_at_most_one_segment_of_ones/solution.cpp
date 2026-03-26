#include <string>

class Solution {
public:
  bool checkOnesSegment(std::string s) {
    const size_t sLen = s.size();

    bool hasOnesSegment = false;

    for (size_t i = 0; i < sLen; ++i) {
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
