#include <string>

class Solution {
public:
  std::string removeStars(std::string s) {
    std::string stack;

    for (const char &c : s) {
      if (c == '*')
        stack.pop_back();
      else
        stack.push_back(c);
    }

    return stack;
  }
};
