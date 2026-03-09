using namespace std;

#include <string>

class Solution {
public:
  int countBinarySubstrings(string s) {
    int count = 0;

    int prev = 0;
    int curr = 1;

    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1])
        ++curr;
      else {
        count += min(curr, prev);
        prev = curr;
        curr = 1;
      }
    }

    return count + min(curr, prev);
  }
};
