using namespace std;

#include <sstream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    for (const char &ch : "!?',;.")
      replace(paragraph.begin(), paragraph.end(), ch, ' ');

    transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
              [](unsigned char ch) { return tolower(ch); });

    unordered_map<string, int> wordsCounter;

    istringstream iss(paragraph);
    string word;

    while (iss >> word)
      ++wordsCounter[word];

    for (const string &word : banned)
      wordsCounter[word] = 0;

    return max_element(
               wordsCounter.begin(), wordsCounter.end(),
               [](const pair<string, int> &p1, const pair<string, int> &p2) {
                 return p1.second < p2.second;
               })
        ->first;
  }
};
