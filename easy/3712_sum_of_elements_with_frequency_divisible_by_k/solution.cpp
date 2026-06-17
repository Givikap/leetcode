#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int sumDivisibleByK(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> numsCounter;
    for (const int &num : nums)
      ++numsCounter[num];

    int numsSum = 0;

    for (const auto &[num, count] : numsCounter) {
      if (count % k == 0)
        numsSum += num * count;
    }

    return numsSum;
  }
};
