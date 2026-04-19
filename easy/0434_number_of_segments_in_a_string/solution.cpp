#include <string>

class Solution {
public:
  int countSegments(std::string s) {
    int count = 0;

    std::string::iterator it = std::find_if(
        s.begin(), s.end(), [](const char ch) { return ch != ' '; });
    while (it != s.end()) {
      while (it != s.end() && *it != ' ')
        ++it;
      ++count;
      while (it != s.end() && *it == ' ')
        ++it;
    }

    return count;
  }
};
