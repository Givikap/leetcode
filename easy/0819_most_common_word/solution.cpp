#include <sstream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::string mostCommonWord(std::string paragraph,
                             std::vector<std::string> &banned) {
    for (const char &ch : "!?',;.")
      replace(paragraph.begin(), paragraph.end(), ch, ' ');

    transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
              [](unsigned char ch) { return tolower(ch); });

    std::unordered_map<std::string, int> wordsCounter;

    std::stringstream iss(paragraph);
    std::string word;

    while (iss >> word)
      ++wordsCounter[word];

    for (const std::string &word : banned)
      wordsCounter[word] = 0;

    return max_element(wordsCounter.begin(), wordsCounter.end(),
                       [](const std::pair<std::string, int> &p1,
                          const std::pair<std::string, int> &p2) {
                         return p1.second < p2.second;
                       })
        ->first;
  }
};
