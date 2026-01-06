using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    unordered_map<char, int> charsCounter, charsCounterCopy;

    for (const char &ch : chars)
      ++charsCounter[ch];

    bool isGood;
    int charsCount = 0;

    for (const string &word : words) {
      charsCounterCopy = charsCounter;
      isGood = true;

      for (const char &ch : word) {
        if (charsCounter.find(ch) == charsCounter.end() ||
            charsCounterCopy[ch] == 0) {
          isGood = false;
          break;
        }

        --charsCounterCopy[ch];
      }

      if (isGood)
        charsCount += word.size();
    }

    return charsCount;
  }
};
