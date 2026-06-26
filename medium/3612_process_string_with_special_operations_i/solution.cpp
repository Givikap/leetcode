#include <string>

class Solution {
public:
  std::string processStr(std::string s) {
    std::string result;

    for (const char &ch : s) {
      if (ch == '*') {
        if (!result.empty())
          result.pop_back();
      } else if (ch == '#')
        result += result;
      else if (ch == '%')
        std::reverse(result.begin(), result.end());
      else
        result += ch;
    }

    return result;
  }
};
