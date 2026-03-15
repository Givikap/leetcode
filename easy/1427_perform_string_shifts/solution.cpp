#include <string>
#include <vector>

class Solution {
public:
  std::string stringShift(std::string s, std::vector<std::vector<int>> &shift) {
    const int sLen = s.size();

    int start = 0;

    std::string shiftedS;
    shiftedS.reserve(sLen);

    for (const std::vector<int> &sh : shift)
      start += sh[1] * (sh[0] == 0 ? 1 : -1);

    start = ((start % sLen) + sLen) % sLen;

    for (int i = start; i < start + sLen; ++i)
      shiftedS.push_back(s[i % sLen]);

    return shiftedS;
  }
};
