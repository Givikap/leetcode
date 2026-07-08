#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> sumAndMultiply(std::string s,
                                  std::vector<std::vector<int>> &queries) {
    const size_t n = s.size();

    const long long mod = 1000000007;
    const long long inv10 = 700000005;

    std::vector<long long> pow10(n + 1, 1);
    std::vector<long long> inv10pow(n + 1, 1);

    for (size_t i = 1; i <= n; ++i) {
      pow10[i] = pow10[i - 1] * 10 % mod;
      inv10pow[i] = inv10pow[i - 1] * inv10 % mod;
    }

    std::vector<long long> cnt(n + 1, 0);
    std::vector<long long> prefixSums(n + 1, 0);
    std::vector<long long> digitsSums(n + 1, 0);

    for (size_t i = 1; i <= n; ++i) {
      long long digit = s[i - 1] - '0';

      cnt[i] = cnt[i - 1] + (digit ? 1 : 0);
      prefixSums[i] =
          (prefixSums[i - 1] + (digit ? digit * inv10pow[cnt[i]] % mod : 0)) %
          mod;
      digitsSums[i] = digitsSums[i - 1] + digit;
    }

    std::vector<int> results;

    for (const std::vector<int> &query : queries) {
      int l = query[0], r = query[1];

      long long x = pow10[cnt[r + 1]] *
                    ((prefixSums[r + 1] - prefixSums[l] + mod) % mod) % mod;
      long long digitSum = digitsSums[r + 1] - digitsSums[l];

      results.push_back(x * digitSum % mod);
    }

    return results;
  }
};
