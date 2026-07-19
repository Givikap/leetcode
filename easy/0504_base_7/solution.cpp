#include <deque>
#include <string>

class Solution {
public:
  std::string convertToBase7(int num) {
    if (abs(num) < 6)
      return std::to_string(num);

    const bool isNegative = num < 0;
    if (isNegative)
      num = -num;

    std::deque<int> dq;

    while (num) {
      dq.push_front(num % 7);
      num /= 7;
    }

    std::string base7Num;

    if (isNegative)
      base7Num.push_back('-');

    for (const int &digit : dq)
      base7Num.push_back(48 + digit);

    return base7Num;
  }
};
