#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int bestPrice = prices[0];
    int maxProfit = 0;

    for (size_t i = 1; i < prices.size(); ++i) {
      if (prices[i] < bestPrice)
        bestPrice = prices[i];
      else
        maxProfit = std::max(maxProfit, prices[i] - bestPrice);
    }

    return maxProfit;
  }
};
