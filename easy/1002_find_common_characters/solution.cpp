#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> commonChars(std::vector<std::string> &words) {
    const int wordsLen = words.size();

    std::vector<int> charsHash(26, 0);

    for (const char &ch : words[0])
      ++charsHash[ch - 'a'];

    for (int i = 1; i < wordsLen; ++i) {
      std::vector<int> wordHash(26, 0);

      for (const char &ch : words[i])
        ++wordHash[ch - 'a'];

      for (int i = 0; i < 26; ++i)
        charsHash[i] = std::min(charsHash[i], wordHash[i]);
    }

    std::vector<std::string> common;

    for (int i = 0; i < 26; ++i) {
      for (int _ = 0; _ < charsHash[i]; ++_)
        common.push_back(std::string(1, 'a' + i));
    }

    return common;
  }
};
