#include <string>

class Solution {
public:
  int countBinarySubstrings(std::string s) {
    int count = 0;

    int prev = 0;
    int curr = 1;

    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i - 1] == s[i])
        ++curr;
      else {
        count += std::min(curr, prev);
        prev = curr;
        curr = 1;
      }
    }

    return count + std::min(curr, prev);
  }
};
