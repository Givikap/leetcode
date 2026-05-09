#include <string>

class Solution {
public:
  int vowelConsonantScore(std::string s) {
    int vowelsCount = 0;
    int consonantsCount = 0;

    for (const char &ch : s) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        ++vowelsCount;
      else if (std::isalpha(ch))
        ++consonantsCount;
    }

    if (consonantsCount == 0)
      return 0;

    return std::floor(vowelsCount / consonantsCount);
  }
};
