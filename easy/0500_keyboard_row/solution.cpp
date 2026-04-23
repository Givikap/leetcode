#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::string> findWords(std::vector<std::string> &words) {
    const std::string rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    const std::vector<std::unordered_set<char>> rowSets = {
        std::unordered_set<char>(rows[0].begin(), rows[0].end()),
        std::unordered_set<char>(rows[1].begin(), rows[1].end()),
        std::unordered_set<char>(rows[2].begin(), rows[2].end()),
    };

    std::vector<std::string> singleRowWords;

    for (const std::string &word : words) {
      for (const std::unordered_set<char> &rowSet : rowSets) {
        bool isSingleRow = true;

        for (const char &ch : word) {
          if (rowSet.find(tolower(ch)) == rowSet.end()) {
            isSingleRow = false;
            break;
          }
        }

        if (isSingleRow)
          singleRowWords.push_back(word);
      }
    }

    return singleRowWords;
  }
};
