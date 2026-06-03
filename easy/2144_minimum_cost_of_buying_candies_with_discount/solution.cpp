#include <vector>

class Solution {
public:
  int minimumCost(std::vector<int> &cost) {
    std::sort(cost.begin(), cost.end());

    int minCost = 0;
    int i = cost.size() - 1;

    while (i > 0) {
      minCost += cost[i - 1] + cost[i];
      i -= 3;
    }

    if (i == 0)
      minCost += cost[0];

    return minCost;
  }
};
