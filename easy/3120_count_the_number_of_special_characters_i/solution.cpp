#include <string>
#include <vector>

class Solution {
public:
  int numberOfSpecialChars(std::string word) {
    std::vector<int> caseMap(26, 0);

    int specialCharsCount = 0;

    for (const char &ch : word) {
      size_t chI;

      if (isupper(ch)) {
        chI = ch - 65;
        caseMap[chI] |= 1;
      } else {
        chI = ch - 97;
        caseMap[chI] |= 2;
      }

      if (caseMap[chI] == 3) {
        caseMap[chI] = 7;
        ++specialCharsCount;
      }
    }

    return specialCharsCount;
  }
};
