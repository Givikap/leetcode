using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  string longestCommonPrefix(vector<string> &words) {
    string longestCommonPrefix = words[0];

    int i, end;

    for (const string &word : words) {
      i = 0;
      end = min(word.size(), longestCommonPrefix.size());

      while (i < end and word[i] == longestCommonPrefix[i])
        ++i;

      if (i == 0)
        return "";
      else if (i < longestCommonPrefix.size())
        longestCommonPrefix = longestCommonPrefix.substr(0, i);
    }

    return longestCommonPrefix;
  }
};
