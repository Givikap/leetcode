#include <string>

class Solution {
public:
  int numberOfSpecialChars(std::string word) {
    const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int specialCharsCount = 0;

    for (size_t i = 0; i < 26; ++i) {
      size_t lowercaseI = word.rfind(lowercaseChars[i]);
      if (lowercaseI == std::string::npos)
        continue;

      size_t uppercaseI = word.find(lowercaseChars[i]);
      if (uppercaseI == std::string::npos)
        continue;

      if (lowercaseI < uppercaseI)
        ++specialCharsCount;
    }

    return specialCharsCount;
  }
};
