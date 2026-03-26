#include <string>
#include <unordered_set>

class Solution {
public:
  std::string trimTrailingVowels(std::string s) {
    std::unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};

    int i = s.size() - 1;
    int vowelsCount = 0;

    while (i >= 0 && vowelsSet.find(s[i--]) != vowelsSet.end())
      ++vowelsCount;

    s.erase(s.end() - vowelsCount, s.end());
    return s;
  }
};
