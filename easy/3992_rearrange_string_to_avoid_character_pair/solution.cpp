#include <algorithm>
#include <string>

class Solution {
public:
  std::string rearrangeString(std::string s, char x, char y) {
    std::string t(std::count(s.begin(), s.end(), y), y);

    for (const char &ch : s) {
      if (ch != y)
        t.push_back(ch);
    }

    return t;
  }
};
