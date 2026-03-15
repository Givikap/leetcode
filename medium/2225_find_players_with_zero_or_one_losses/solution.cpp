#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  findWinners(std::vector<std::vector<int>> &matches) {
    std::unordered_map<int, int> lossCounter;

    for (const std::vector<int> &match : matches) {
      lossCounter[match[0]];
      ++lossCounter[match[1]];
    }

    std::vector<std::vector<int>> answer(2);

    for (const auto &[loser, count] : lossCounter) {
      if (count < 2)
        answer[count].push_back(loser);
    }

    sort(answer[0].begin(), answer[0].end());
    sort(answer[1].begin(), answer[1].end());

    return answer;
  }
};
