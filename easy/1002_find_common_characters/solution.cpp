using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    vector<unordered_map<char, int>> wordCounters;

    for (const string &word : words) {
      unordered_map<char, int> wordCounter;

      for (const char &ch : word)
        ++wordCounter[ch];

      wordCounters.push_back(wordCounter);
    }

    vector<string> common;

    for (char ch = 'a'; ch < '{'; ++ch) {
      int minCount = 101;
      bool isCommon = true;

      for (unordered_map<char, int> &wordCounter : wordCounters) {
        minCount = min(minCount, wordCounter[ch]);

        if (minCount == 0) {
          isCommon = false;
          break;
        }
      }

      if (isCommon)
        for (int _ = 0; _ < minCount; ++_)
          common.push_back(string(1, ch));
    }

    return common;
  }
};
