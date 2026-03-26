#include <string>

class Solution {
public:
  int minOperations(std::string s) {
    if (s.size() == 1)
      return 0;
    if (s.size() == 2)
      return s[0] == s[1];

    int changesCount = 0;
    int curr = 0;

    for (size_t i = 0; i < s.size(); ++i) {
      if ((curr == 0 && s[i] != '0') || (curr == 1 && s[i] != '1'))
        ++changesCount;

      curr = !curr;
    }

    return std::min(changesCount, (int)s.size() - changesCount);
  }
};
