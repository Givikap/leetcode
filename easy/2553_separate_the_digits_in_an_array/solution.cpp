#include <vector>

class Solution {
public:
  std::vector<int> separateDigits(std::vector<int> &nums) {
    std::vector<int> digits;

    for (const int &num : nums) {
      for (const char &ch : std::to_string(num)) {
        digits.push_back(ch - '0');
      }
    }

    return digits;
  }
};
