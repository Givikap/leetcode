#include <vector>

class Solution {
public:
  int maxDigitRange(std::vector<int> &nums) {
    int maxDigitRange = 0;
    int maxDigitRangeSum = 0;

    for (const int &num : nums) {
      int numCopy = num;

      int minDigit = 9;
      int maxDigit = 0;

      while (numCopy) {
        int digit = numCopy % 10;
        minDigit = std::min(minDigit, digit);
        maxDigit = std::max(maxDigit, digit);

        numCopy /= 10;
      }

      int digitRange = maxDigit - minDigit;

      if (digitRange > maxDigitRange) {
        maxDigitRange = digitRange;
        maxDigitRangeSum = num;
      } else if (digitRange == maxDigitRange)
        maxDigitRangeSum += num;
    }

    return maxDigitRangeSum;
  }
};
