using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int myAtoi(string s) {
    const int sLen = s.size();

    vector<int> digits;
    digits.reserve(sLen);

    bool isPositive = true;

    int i = 0;
    while (i < sLen && s[i] == ' ')
      ++i;

    if (s[i] == '-') {
      isPositive = false;
      ++i;
    } else if (s[i] == '+')
      ++i;

    for (; i < sLen; ++i) {
      if (isdigit(s[i]))
        digits.push_back(s[i] - '0');
      else
        break;
    }

    long long num = 0;

    for (const int digit : digits) {
      num = num * 10 + digit;

      if (isPositive && num > INT_MAX)
        return INT_MAX;
      if (!isPositive && -num < INT_MIN)
        return INT_MIN;
    }

    return (int)(num * (isPositive ? 1 : -1));
  }
};
