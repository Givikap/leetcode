using namespace std;

#include <algorithm>
#include <string>

class Solution {
public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k)
      reverse(begin(s) + i, begin(s) + min(i + k, (int)s.size()));

    return s;
  }
};
