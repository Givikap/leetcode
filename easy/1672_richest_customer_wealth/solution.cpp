using namespace std;

#include <numeric>
#include <vector>

class Solution {
public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int maxWealth = 0;
    int accountSum = 0;

    for (const vector<int> &account : accounts) {
      accountSum = reduce(account.begin(), account.end());

      if (maxWealth < accountSum)
        maxWealth = accountSum;
    }

    return maxWealth;
  }
};
