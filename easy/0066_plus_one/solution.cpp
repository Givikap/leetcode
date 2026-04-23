#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    for (size_t i = digits.size() - 1; i >= 0; --i) {
      digits[i] += 1;

      if (digits[i] == 10) {
        digits[i] = 0;

        if (i)
          continue;

        digits.insert(digits.begin(), 1);
      }

      break;
    }

    return digits;
  }
};
