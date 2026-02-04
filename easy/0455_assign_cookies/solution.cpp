using namespace std;

#include <vector>

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    const int gLen = g.size();
    const int sLen = s.size();
    int gi = 0;
    int si = 0;

    int cookiesCount = 0;

    while (gi < gLen && si < sLen) {
      if (g[gi] <= s[si++]) {
        ++gi;
        ++cookiesCount;
      }
    }

    return cookiesCount;
  }
};
