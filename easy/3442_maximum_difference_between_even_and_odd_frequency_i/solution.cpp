#include <string>
#include <vector>

class Solution {
public:
  int maxDifference(std::string s) {
    std::vector<int> frequencies(26, 0);

    for (const char &c : s)
      ++frequencies[c - 'a'];

    int maxOddFrequency = 0;
    int minEvenFrequency = 101;

    for (const int &frequency : frequencies) {
      if (frequency % 2 == 0 && frequency != 0)
        minEvenFrequency = std::min(frequency, minEvenFrequency);
      else
        maxOddFrequency = std::max(frequency, maxOddFrequency);
    }

    return maxOddFrequency - minEvenFrequency;
  }
};
