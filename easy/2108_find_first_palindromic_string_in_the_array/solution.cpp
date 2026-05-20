#include <string>
#include <vector>

class Solution {
public:
  std::string firstPalindrome(std::vector<std::string> &words) {
    for (const std::string &word : words) {
      if (std::equal(word.begin(), word.end(), word.rbegin()))
        return word;
    }

    return "";
  }
};
