using namespace std;

#include <string>

class Solution {
public:
  int minOperations(string s) {
    if (s.size() == 1)
      return 0;
    if (s.size() == 2)
      return s[0] == s[1];

    int zeros = 0, ones = 0;
    int zero = 1;

    for (int i = 0; i < s.size(); ++i) {
      if ((zero && s[i] != '0') || (!zero && s[i] != '1'))
        ++zeros;
      if ((zero && s[i] != '1') || (!zero && s[i] != '0'))
        ++ones;

      zero = !zero;
    }

    return min(zeros, ones);
  }
};
