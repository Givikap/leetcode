#include <vector>

class Solution {
public:
  int maxIceCream(std::vector<int> &costs, int coins) {
    std::vector<int> costsCounter(
        *std::max_element(costs.begin(), costs.end()) + 1, 0);
    for (const int &cost : costs)
      ++costsCounter[cost];

    int iceCreamCount = 0;

    for (int cost = 1; cost < costsCounter.size(); ++cost) {
      int count = costsCounter[cost];
      if (!count)
        continue;

      long iceCreamsCost = static_cast<long>(cost) * count;
      if (coins >= iceCreamsCost) {
        coins -= iceCreamsCost;
        iceCreamCount += count;
      } else {
        while (coins >= cost) {
          coins -= cost;
          ++iceCreamCount;
        }
      }
    }

    return iceCreamCount;
  }
};
