#include <vector>

class Solution {
public:
  std::vector<int> selfDividingNumbers(int left, int right) {
    std::vector<int> dividingNums;

    for (int num = left; num < right + 1; ++num) {
      int numCopy = num;
      while (numCopy) {
        int digit = numCopy % 10;

        if (digit == 0 || num % digit != 0)
          break;

        numCopy /= 10;
      }

      if (numCopy == 0)
        dividingNums.push_back(num);
    }

    return dividingNums;
  }
};
