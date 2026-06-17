#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int sumDivisibleByK(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> numsCounter;
    for (const int &num : nums)
      ++numsCounter[num];

    return std::accumulate(
        numsCounter.begin(), numsCounter.end(), 0,
        [k](int sum, const auto &pair) {
          return sum + (pair.second % k == 0 ? pair.first * pair.second : 0);
        });
  }
};
