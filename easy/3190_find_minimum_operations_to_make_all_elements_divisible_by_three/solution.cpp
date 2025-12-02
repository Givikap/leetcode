using namespace std;

#include <vector>

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int operationsNum = 0;

    for (int &num : nums) {
      operationsNum += num % 3 != 0;
    }

    return operationsNum;
  }
};
