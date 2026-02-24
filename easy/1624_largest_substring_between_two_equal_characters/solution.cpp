using namespace std;

#include <vector>

class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<int> cArray(26, -1);

    int maxLength = -1;

    for (int i = 0; i < s.size(); ++i) {
      if (cArray[s[i] - 'a'] != -1)
        maxLength = max(maxLength, i - cArray[s[i] - 'a'] - 1);
      else
        cArray[s[i] - 'a'] = i;
    }

    return maxLength;
  }
};
