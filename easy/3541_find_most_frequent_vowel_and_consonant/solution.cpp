using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
  int maxFreqSum(string s) {
    unordered_map<char, int> chCounter;

    for (char &ch : s)
      chCounter[ch] += 1;

    int maxVowelCount = 0;
    int maxConsonantCount = 0;

    for (const auto &[ch, count] : chCounter) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        if (maxVowelCount < count)
          maxVowelCount = count;
      } else {
        if (maxConsonantCount < count)
          maxConsonantCount = count;
      }
    }

    return maxVowelCount + maxConsonantCount;
  }
};
