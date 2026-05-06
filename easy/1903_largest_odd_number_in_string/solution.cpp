#include <string>

class Solution {
public:
  std::string largestOddNumber(std::string num) {
    size_t lastOdd = 0;

    for (size_t i = 0; i < num.size(); ++i) {
      if ((num[i] - 48) % 2 == 1)
        lastOdd = i + 1;
    }

    return num.substr(0, lastOdd);
  }
};
