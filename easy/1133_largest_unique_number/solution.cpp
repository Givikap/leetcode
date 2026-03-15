#include <unordered_map>
#include <vector>

class Solution {
public:
  int largestUniqueNumber(std::vector<int> &nums) {
    std::unordered_map<int, int> numsCounter;

    for (const int &num : nums)
      ++numsCounter[num];

    int largestNum = -1;

    for (const auto &[num, count] : numsCounter) {
      if (count == 1)
        largestNum = std::max(num, largestNum);
    }

    return largestNum;
  }
};
