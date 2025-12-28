using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
  int maxDifference(string s) {
    unordered_map<char, int> sCounter;

    for (const char &c : s)
      ++sCounter[c];

    int maxOddFrequency = 0;
    int minEvenFrequency = 101;

    for (const auto &[_, frequency] : sCounter) {
      if (frequency % 2)
        maxOddFrequency = max(frequency, maxOddFrequency);
      else
        minEvenFrequency = min(frequency, minEvenFrequency);
    }

    return maxOddFrequency - minEvenFrequency;
  }
};
