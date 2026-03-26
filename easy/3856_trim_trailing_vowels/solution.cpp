#include <string>
#include <unordered_set>

class Solution {
public:
  std::string trimTrailingVowels(std::string s) {
    std::unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};

    while (!s.empty() && vowelsSet.find(s.back()) != vowelsSet.end())
      s.pop_back();

    return s;
  }
};
