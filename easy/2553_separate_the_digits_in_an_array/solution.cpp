#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> separateDigits(std::vector<int> &nums) {
    std::vector<int> digits;

    for (int &num : nums) {
      std::stack<int> s;

      while (num) {
        s.push(num % 10);
        num /= 10;
      }

      while (!s.empty()) {
        digits.push_back(s.top());
        s.pop();
      }
    }

    return digits;
  }
};
