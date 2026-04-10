#include <deque>
#include <string>

class Solution {
public:
  std::string largestEven(std::string s) {
    while (!s.empty()) {
      if ((s.back() - '0') % 2 == 0)
        return s;

      s.pop_back();
    }

    return "";
  }
};
