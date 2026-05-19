#include <string>

class Solution {
public:
  bool validWordAbbreviation(std::string word, std::string abbr) {
    const size_t wordLen = word.size();
    const size_t abbrLen = abbr.size();

    size_t wordI = 0;
    size_t abbrI = 0;

    while (wordI < wordLen) {
      if (word[wordI] == abbr[abbrI]) {
        ++wordI;
        ++abbrI;
      } else if (abbr[abbrI] >= '0' && abbr[abbrI] <= '9') {
        if (abbr[abbrI] == '0')
          return false;

        size_t jump = 0;

        while (abbrI < abbrLen && std::isdigit(abbr[abbrI]))
          jump = jump * 10 + (abbr[abbrI++] - '0');

        wordI += jump;
      } else {
        return false;
      }
    }

    return wordI == wordLen && abbrI == abbrLen;
  }
};
