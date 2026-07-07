#include <numeric>
#include <vector>

class Solution {
public:
  long long sumAndMultiply(int n) {
    std::vector<int> digits;

    while (n) {
      int digit = n % 10;

      if (digit != 0)
        digits.push_back(digit);

      n /= 10;
    }

    int digitsSum = std::reduce(digits.begin(), digits.end());

    while (!digits.empty()) {
      n = n * 10 + digits.back();
      digits.pop_back();
    }

    return (long long)n * digitsSum;
  }
};
