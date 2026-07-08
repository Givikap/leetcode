#include <string>
#include <unordered_map>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size())
      return false;

    std::unordered_map<char, int> sCounter, tCounter;

    for (size_t i = 0; i < s.size(); ++i) {
      ++sCounter[s[i]];
      ++tCounter[t[i]];
    }

    return sCounter == tCounter;
  }
};
