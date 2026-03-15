#include <numeric>
#include <vector>

class Solution {
public:
  int maximumWealth(std::vector<std::vector<int>> &accounts) {
    int maxWealth = 0;
    int accountSum = 0;

    for (const std::vector<int> &account : accounts) {
      accountSum = reduce(account.begin(), account.end());

      if (maxWealth < accountSum)
        maxWealth = accountSum;
    }

    return maxWealth;
  }
};
