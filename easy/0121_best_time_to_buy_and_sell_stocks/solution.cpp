#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    const size_t n = prices.size();

    std::vector<int> postfixMaxPrice(n);
    postfixMaxPrice[n - 1] = 0;

    size_t i = n - 1;
    while (i--)
      postfixMaxPrice[i] = std::max(postfixMaxPrice[i + 1], prices[i + 1]);

    int maxProfit = 0;

    for (i = 0; i < n - 1; ++i)
      maxProfit = std::max(maxProfit, postfixMaxPrice[i] - prices[i]);

    return maxProfit;
  }
};
