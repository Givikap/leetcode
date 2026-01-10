using namespace std;

#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  int maxScore(string s) {
    const int sLen = s.size();

    vector<int> sList;

    for (const char &ch : s)
      sList.push_back(ch - '0');

    int left = sList[0] == 0 ? 1 : 0;
    int right = reduce(sList.begin(), sList.end()) - sList[0];

    int maxScore = 0;

    for (int i = 0; i < sLen - 1; ++i) {
      maxScore = max(left + right, maxScore);

      left += sList[i + 1] == 0 ? 1 : 0;
      right -= sList[i + 1];
    }

    return maxScore;
  }
};
