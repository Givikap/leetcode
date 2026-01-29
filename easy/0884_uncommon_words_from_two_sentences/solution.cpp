using namespace std;

#include <sstream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> uncommonWords;

    unordered_map<string, int> s1Counter, s2Counter;

    vector<string> words;
    string word;

    for (const string &s : vector<string>{s1, s2}) {
      istringstream iss(s);

      while (getline(iss, word, ' '))
        words.push_back(word);

      for (const string &word : words)
        s == s1 ? ++s1Counter[word] : ++s2Counter[word];

      words.clear();
    }

    for (const auto &[word, count] : s1Counter) {
      if (count == 1 && s2Counter.find(word) == s2Counter.end())
        uncommonWords.push_back(word);
    }

    for (const auto &[word, count] : s2Counter) {
      if (count == 1 && s1Counter.find(word) == s1Counter.end())
        uncommonWords.push_back(word);
    }

    return uncommonWords;
  }
};
