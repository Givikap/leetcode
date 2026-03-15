#include <string>
#include <vector>

class Solution {
public:
  int myAtoi(std::string s) {
    const int sLen = s.size();

    int i = 0;
    while (i < sLen && s[i] == ' ')
      ++i;

    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
      sign = s[i] == '-' ? -1 : 1;
      ++i;
    }

    long long num = 0;

    while (i < sLen && isdigit(s[i])) {
      num = num * 10 + (s[i++] - '0');

      if (sign == 1 && num > INT_MAX)
        return INT_MAX;
      if (sign == -1 && -num < INT_MIN)
        return INT_MIN;
    }

    return (int)(sign * num);
  }
};
