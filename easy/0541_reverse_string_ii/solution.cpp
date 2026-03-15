#include <algorithm>
#include <string>

class Solution {
public:
  std::string reverseStr(std::string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k)
      reverse(begin(s) + i, begin(s) + std::min(i + k, (int)s.size()));

    return s;
  }
};
