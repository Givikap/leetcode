#include <string>
#include <vector>

class Solution {
public:
  bool arrayStringsAreEqual(std::vector<std::string> &array1,
                            std::vector<std::string> &array2) {
    std::vector<char> word1, word2;

    for (const std::string &subWord : array1) {
      for (const char &ch : subWord)
        word1.push_back(ch);
    }
    for (const std::string &subWord : array2) {
      for (const char &ch : subWord)
        word2.push_back(ch);
    }

    return word1 == word2;
  }
};
