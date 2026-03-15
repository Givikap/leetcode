#include <sstream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> uncommonFromSentences(std::string s1,
                                                 std::string s2) {
    std::vector<std::string> uncommonWords;

    std::unordered_map<std::string, int> s1Counter, s2Counter;

    std::vector<std::string> words;
    std::string word;

    for (const std::string &s : std::vector<std::string>{s1, s2}) {
      std::stringstream iss(s);

      while (getline(iss, word, ' '))
        words.push_back(word);

      for (const std::string &word : words)
        s == s1 ? ++s1Counter[word] : ++s2Counter[word];

      words.clear();
    }

    for (const auto &[word, count] : s1Counter) {
      if (count == 1 && s2Counter.find(word) == s2Counter.end())
        uncommonWords.push_back(word);
    }

    for (const auto &[word, count] : s2Counter) {
      if (count == 1 && s1Counter.find(word) == s1Counter.end())
        uncommonWords.push_back(word);
    }

    return uncommonWords;
  }
};
