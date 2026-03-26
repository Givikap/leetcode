#include <string>
#include <vector>

class Solution {
public:
  std::string restoreString(std::string s, std::vector<int> &indices) {
    std::string shuffledS(s.size(), ' ');

    for (size_t i = 0; i < s.size(); ++i)
      shuffledS[indices[i]] = s[i];

    return shuffledS;
  }
};
