#include <vector>

class Solution {
public:
  std::vector<int> sequentialDigits(int low, int high) {
    const int digits[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> sequentialNums;

    for (size_t count = 1; count < 10; ++count) {
      for (size_t i = 0; i < 9; ++i) {
        if (i == 10 - count)
          break;

        int sequentialNum = 0;

        for (size_t j = 0; j < count; ++j)
          sequentialNum = sequentialNum * 10 + digits[i + j];

        if (low <= sequentialNum && sequentialNum <= high)
          sequentialNums.push_back(sequentialNum);
      }
    }

    return sequentialNums;
  }
};
