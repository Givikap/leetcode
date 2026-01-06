using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    vector<int> charsCounter(26, 0), charsCounterCopy;

    for (const char &ch : chars)
      ++charsCounter[ch - 'a'];

    bool isGood;
    int charsCount = 0;

    for (const string &word : words) {
      charsCounterCopy = charsCounter;
      isGood = true;

      for (const char &ch : word) {
        if (charsCounterCopy[ch - 'a'] == 0) {
          isGood = false;
          break;
        }

        --charsCounterCopy[ch - 'a'];
      }

      if (isGood)
        charsCount += word.size();
    }

    return charsCount;
  }
};
