using namespace std;

#include <vector>

class Solution {
public:
  int arraySign(vector<int> &nums) {
    int numsProduct = 1;

    for (int &num : nums) {
      if (num == 0) {
        numsProduct = 0;
        break;
      } else if (num < 0) {
        numsProduct *= -1;
      }
    }

    if (numsProduct > 0)
      return 1;
    else if (numsProduct == 0)
      return 0;
    else
      return -1;
  }
};
