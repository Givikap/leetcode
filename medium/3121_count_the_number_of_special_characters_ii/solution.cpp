#include <string>
#include <vector>

class Solution {
public:
  int numberOfSpecialChars(std::string word) {
    std::vector<size_t> lastLowercaseMap(26, -1);
    std::vector<size_t> firstUppercaseMap(26, -1);

    for (size_t i = 0; i < word.size(); ++i) {
      char ch = word[i];

      if (islower(ch))
        lastLowercaseMap[ch - 'a'] = i;
      else if (firstUppercaseMap[ch - 'A'] == -1)
        firstUppercaseMap[ch - 'A'] = i;
    }

    int specialCharsCount = 0;

    for (size_t i = 0; i < 26; ++i) {
      if (firstUppercaseMap[i] != -1 &&
          lastLowercaseMap[i] < firstUppercaseMap[i])
        ++specialCharsCount;
    }

    return specialCharsCount;
  }
};
