#include <numeric>
#include <vector>

class Solution {
public:
  long long gcdSum(std::vector<int> &nums) {
    const size_t n = nums.size();

    std::vector<int> mx(n, nums[0]);
    std::vector<int> prefixGcd(n);

    size_t i;
    for (i = 1; i < n; ++i)
      mx[i] = std::max(mx[i - 1], nums[i]);

    for (i = 0; i < n; ++i)
      prefixGcd[i] = std::gcd(nums[i], mx[i]);

    std::sort(prefixGcd.begin(), prefixGcd.end());

    long long gcdSum = 0;

    for (i = 0; i < n / 2; ++i)
      gcdSum += std::gcd(prefixGcd[i], prefixGcd[n - i - 1]);

    return gcdSum;
  }
};
