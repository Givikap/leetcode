using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  string restoreString(string s, vector<int> &indices) {
    const int sLen = s.size();

    string shuffledS(s.size(), ' ');

    for (int i = 0; i < sLen; ++i)
      shuffledS[indices[i]] = s[i];

    return shuffledS;
  }
};
