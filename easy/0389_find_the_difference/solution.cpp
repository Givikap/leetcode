using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> sCounter, tCounter;

    for (char &ch : s)
      ++sCounter[ch];
    for (char &ch : t)
      ++tCounter[ch];

    for (const auto &[ch, count] : tCounter) {
      if (sCounter.find(ch) == sCounter.end() || sCounter[ch] != count)
        return ch;
    }

    return ' ';
  }
};
