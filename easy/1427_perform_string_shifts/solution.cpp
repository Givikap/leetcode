using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  string stringShift(string s, vector<vector<int>> &shift) {
    const int sLen = s.size();

    int start = 0;

    string shiftedS;
    shiftedS.reserve(sLen);

    for (const vector<int> &sh : shift)
      start += sh[1] * (sh[0] == 0 ? 1 : -1);

    start = ((start % sLen) + sLen) % sLen;

    for (int i = start; i < start + sLen; ++i)
      shiftedS.push_back(s[i % sLen]);

    return shiftedS;
  }
};
