using namespace std;

#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    unordered_map<int, int> lossCounter;

    for (const vector<int> &match : matches) {
      lossCounter[match[0]];
      ++lossCounter[match[1]];
    }

    vector<vector<int>> answer(2);

    for (const auto &[loser, count] : lossCounter) {
      if (count < 2)
        answer[count].push_back(loser);
    }

    sort(answer[0].begin(), answer[0].end());
    sort(answer[1].begin(), answer[1].end());

    return answer;
  }
};
