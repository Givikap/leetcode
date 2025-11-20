using namespace std;

#include <string>

class Solution {
public:
  string reverseStr(string s, int k) {
    string reversedS;

    int start = 0;
    int end = min(k - 1, (int)s.size() - 1);

    int i;

    while (true) {
      for (i = end; i > start - 1; i--)
        reversedS.push_back(s[i]);

      start = end + 1;
      end = min(end + k + 1, (int)s.size());

      if (start >= s.size())
        break;

      for (i = start; i < end; i++)
        reversedS.push_back(s[i]);

      start = end;
      end = min(start + k - 1, (int)s.size() - 1);
    }

    return reversedS;
  }
};
