using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int maxDifference(string s) {
    vector<int> frequencies(26, 0);

    for (const char &c : s)
      ++frequencies[c - 'a'];

    int maxOddFrequency = 0;
    int minEvenFrequency = 101;

    for (const int &frequency : frequencies) {
      if (frequency % 2 == 0 && frequency != 0)
        minEvenFrequency = min(frequency, minEvenFrequency);
      else
        maxOddFrequency = max(frequency, maxOddFrequency);
    }

    return maxOddFrequency - minEvenFrequency;
  }
};
