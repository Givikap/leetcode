using namespace std;

#include <string>

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string newWord;

    for (int i = 0; i < max(word1.size(), word2.size()); i++) {
      if (i < word1.size())
        newWord.push_back(word1[i]);
      if (i < word2.size())
        newWord.push_back(word2[i]);
    }

    return newWord;
  }
};
