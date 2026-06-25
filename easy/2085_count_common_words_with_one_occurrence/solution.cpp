#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int countWords(std::vector<std::string> &words1,
                 std::vector<std::string> &words2) {
    std::unordered_map<std::string, int> words1Counter;
    for (const std::string &word : words1)
      ++words1Counter[word];

    std::unordered_map<std::string, int> words2Counter;
    for (const std::string &word : words2)
      ++words2Counter[word];

    int wordsCount = 0;

    for (const auto &[word, count] : words1Counter) {
      if (count == 1 && words2Counter[word] == 1)
        ++wordsCount;
    }

    return wordsCount;
  }
};
