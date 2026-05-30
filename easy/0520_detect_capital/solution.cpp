#include <string>

class Solution {
public:
  bool detectCapitalUse(std::string word) {
    if (word.size() == 1)
      return true;

    if (isupper(word[0]) && isupper(word[1])) {
      for (size_t i = 1; i < word.size(); ++i) {
        if (islower(word[i]))
          return false;
      }
    } else {
      for (size_t i = 1; i < word.size(); ++i) {
        if (isupper(word[i]))
          return false;
      }
    }

    return true;
  }
};
