#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &words) {
    std::string longestCommonPrefix = words[0];

    int i, end;

    for (const std::string &word : words) {
      i = 0;
      end = std::min(word.size(), longestCommonPrefix.size());

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
