
#include <string>

class Solution {
public:
  int numberOfSubstrings(std::string s) {
    int lastAbcMap[3] = {-1, -1, -1};
    int substringsCount = 0;

    for (int i = 0; i < static_cast<int>(s.length()); ++i) {
      lastAbcMap[s[i] - 'a'] = i;
      substringsCount +=
          std::min(lastAbcMap[0], std::min(lastAbcMap[1], lastAbcMap[2])) + 1;
    }

    return substringsCount;
  }
};
