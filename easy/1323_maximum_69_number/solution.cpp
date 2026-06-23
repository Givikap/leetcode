#include <vector>

class Solution {
public:
  int maximum69Number(int num) {
    std::vector<int> digits;

    while (num) {
      digits.push_back(num % 10);
      num /= 10;
    }

    bool numChanged = false;

    while (!digits.empty()) {
      int digit = digits.back();
      digits.pop_back();

      if (!numChanged && digit == 6) {
        numChanged = true;
        digit = 9;
      }

      num = num * 10 + digit;
    }

    return num;
  }
};
