using namespace std;

#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    set<int> winners;
    set<int> oneLoss;
    set<int> manyLosses;

    for (const vector<int> &match : matches) {
      int winner = match[0];
      int loser = match[1];

      winners.insert(winner);

      if (oneLoss.find(loser) == oneLoss.end())
        oneLoss.insert(loser);
      else
        manyLosses.insert(loser);
    }

    vector<vector<int>> answer(2);
    set<int> temp;

    set_difference(winners.begin(), winners.end(), oneLoss.begin(),
                   oneLoss.end(), inserter(temp, temp.begin()));
    set_difference(temp.begin(), temp.end(), manyLosses.begin(),
                   manyLosses.end(), back_inserter(answer[0]));

    set_difference(oneLoss.begin(), oneLoss.end(), manyLosses.begin(),
                   manyLosses.end(), back_inserter(answer[1]));

    return answer;
  }
};
