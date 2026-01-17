using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool makeEqual(vector<string> &words) {
    const int wordsLen = words.size();

    unordered_map<char, int> charsCounter;

    for (const string &word : words) {
      for (const char &ch : word)
        ++charsCounter[ch];
    }

    for (const auto &[_, count] : charsCounter) {
      if (count % wordsLen != 0)
        return false;
    }

    return true;
  }
};
