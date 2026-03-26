#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> commonChars(std::vector<std::string> &words) {
    std::vector<int> charsHash(26, 0);

    for (const char &ch : words[0])
      ++charsHash[ch - 'a'];

    for (size_t i = 1; i < words.size(); ++i) {
      std::vector<int> wordHash(26, 0);

      for (const char &ch : words[i])
        ++wordHash[ch - 'a'];

      for (size_t j = 0; j < 26; ++j)
        charsHash[j] = std::min(charsHash[j], wordHash[j]);
    }

    std::vector<std::string> common;

    for (int i = 0; i < 26; ++i) {
      for (int _ = 0; _ < charsHash[i]; ++_)
        common.push_back(std::string(1, 'a' + i));
    }

    return common;
  }
};
