using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    const int wordsLen = words.size();

    vector<int> charsHash(26, 0);

    for (const char &ch : words[0])
      ++charsHash[ch - 'a'];

    for (int i = 1; i < wordsLen; ++i) {
      vector<int> wordHash(26, 0);

      for (const char &ch : words[i])
        ++wordHash[ch - 'a'];

      for (int i = 0; i < 26; ++i)
        charsHash[i] = min(charsHash[i], wordHash[i]);
    }

    vector<string> common;

    for (int i = 0; i < 26; ++i) {
      for (int _ = 0; _ < charsHash[i]; ++_)
        common.push_back(string(1, 'a' + i));
    }

    return common;
  }
};
