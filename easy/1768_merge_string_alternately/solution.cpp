using namespace std;

#include <string>

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    const int word1Length = word1.length();
    const int word2Length = word2.length();

    string newWord;
    newWord.reserve(word1Length + word2Length);

    int i = 0;

    while (i < word1Length || i < word2Length) {
      if (i < word1Length)
        newWord += word1[i];
      if (i < word2Length)
        newWord += word2[i];
      i++;
    }

    return newWord;
  }
};
