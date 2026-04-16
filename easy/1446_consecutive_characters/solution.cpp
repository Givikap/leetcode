#include <string>

class Solution {
public:
  int maxPower(std::string s) {
    int len = 1;
    int maxLen = 1;

    for (size_t i = 0; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1])
        ++len;
      else {
        maxLen = std::max(maxLen, len);
        len = 1;
      }
    }

    return std::max(maxLen, len);
  }
};
