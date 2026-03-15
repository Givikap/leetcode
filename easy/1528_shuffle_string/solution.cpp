#include <string>
#include <vector>

class Solution {
public:
  std::string restoreString(std::string s, std::vector<int> &indices) {
    const int sLen = s.size();

    std::string shuffledS(s.size(), ' ');

    for (int i = 0; i < sLen; ++i)
      shuffledS[indices[i]] = s[i];

    return shuffledS;
  }
};
