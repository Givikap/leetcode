#include <string>
#include <vector>

class Solution {
public:
  std::string mapWordWeights(std::vector<std::string> &words,
                             std::vector<int> &weights) {
    std::string letters;
    letters.reserve(words.size());

    for (const std::string &word : words) {
      int val = 0;
      for (const char &c : word)
        val += weights[c - 97];

      letters.push_back(122 - (val % 26));
    }

    return letters;
  }
};
