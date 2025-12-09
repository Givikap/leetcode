using namespace std;

#include <string>

class Solution {
public:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  bool isValid(string word) {
    if (word.size() < 3)
      return false;

    bool containsVowel = false;
    bool containsConsonant = false;

    for (char &c : word) {
      if (!isalnum(c))
        return false;

      c = tolower(c);

      if (!containsVowel && isVowel(c))
        containsVowel = true;
      if (!isVowel(c) && !isdigit(c))
        containsConsonant = true;
    }

    return containsVowel && containsConsonant;
  }
};
