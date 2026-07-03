#include <string>

class Solution {
public:
  int findLUSlength(std::string a, std::string b) {
    if (std::equal(a.begin(), a.end(), b.begin(), b.end()))
      return -1;
    else
      return static_cast<int>(std::max(a.size(), b.size()));
  }
};
