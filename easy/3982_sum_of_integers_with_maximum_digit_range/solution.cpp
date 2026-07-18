#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxDigitRange(std::vector<int> &nums) {
    std::unordered_map<int, int> digitRangesMap;
    std::unordered_map<int, int> numsCounter;

    int maxDigitRange = 0;

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

      digitRangesMap[num] = maxDigit - minDigit;
      ++numsCounter[num];

      maxDigitRange = std::max(maxDigitRange, maxDigit - minDigit);
    }

    int maxDigitRangeSum = 0;

    for (const auto &[num, digitRange] : digitRangesMap) {
      if (digitRange == maxDigitRange)
        maxDigitRangeSum += num * numsCounter[num];
    }

    return maxDigitRangeSum;
  }
};
