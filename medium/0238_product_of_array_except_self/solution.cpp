using namespace std;

#include <vector>

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    const int numsLen = nums.size();

    vector<int> numProducts(numsLen, 1);

    int prefix = 1;
    for (int i = 0; i < numsLen; ++i) {
      numProducts[i] = prefix;
      prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = numsLen - 1; i > -1; --i) {
      numProducts[i] *= suffix;
      suffix *= nums[i];
    }

    return numProducts;
  }
};
