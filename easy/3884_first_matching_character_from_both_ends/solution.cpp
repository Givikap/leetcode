#include <string>

class Solution {
public:
  int firstMatchingIndex(std::string s) {
    const size_t n = s.size();

    for (size_t i = 0; i < n; ++i) {
      if (s[i] == s[n - i - 1])
        return i;
    }

    return -1;
  }
};
