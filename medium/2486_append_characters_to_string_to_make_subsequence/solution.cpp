#include <string>

class Solution {
public:
  int appendCharacters(std::string s, std::string t) {
    const int sLen = s.size();
    const int tLen = t.size();

    int si = 0, ti = 0;

    while (si < sLen && ti < tLen) {
      if (s[si++] == t[ti])
        ++ti;
    }

    return tLen - ti;
  }
};
