#include <map>
#include <vector>

class Solution {
public:
  bool isGood(std::vector<int> &nums) {
    std::map<int, int> numsCounter;
    for (const int &num : nums)
      ++numsCounter[num];

    const int maxNum = numsCounter.rbegin()->first;

    if (numsCounter[maxNum] != 2)
      return false;

    for (int num = 1; num < maxNum; ++num) {
      if (numsCounter[num] != 1)
        return false;
    }

    return true;
  }
};
