#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    const size_t numsLen = nums.size();

    std::vector<int> numProducts(numsLen, 1);

    int prefix = 1;
    for (size_t i = 0; i < numsLen; ++i) {
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
