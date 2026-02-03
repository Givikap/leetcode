using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  bool arrayStringsAreEqual(vector<string> &array1, vector<string> &array2) {
    vector<char> word1, word2;

    for (const string &subWord : array1) {
      for (const char &ch : subWord)
        word1.push_back(ch);
    }
    for (const string &subWord : array2) {
      for (const char &ch : subWord)
        word2.push_back(ch);
    }

    return word1 == word2;
  }
};
