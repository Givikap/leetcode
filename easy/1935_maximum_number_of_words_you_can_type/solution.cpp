#include <string>
#include <unordered_set>

class Solution {
public:
  int canBeTypedWords(std::string text, std::string brokenLetters) {
    std::unordered_set<char> brokenLettersSet(brokenLetters.begin(),
                                              brokenLetters.end());

    int wordsCount = 0;

    for (int i = 0; i < text.size(); i++) {
      if (brokenLettersSet.find(text[i]) != brokenLettersSet.end())
        while (i < text.size() - 1 && text[++i] != ' ') {
        }
      else if (text[i] == ' ' || i == text.size() - 1)
        ++wordsCount;
    }

    return wordsCount;
  }
};
