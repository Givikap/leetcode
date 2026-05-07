#include <map>
#include <vector>

class Solution {
public:
  std::vector<int> minDistinctFreqPair(std::vector<int> &nums) {
    std::map<int, int> numsCounter;
    for (const int &num : nums)
      ++numsCounter[num];

    for (auto xIt = numsCounter.begin(); xIt != numsCounter.end(); ++xIt) {
      for (auto yIt = std::next(xIt); yIt != numsCounter.end(); ++yIt) {
        if (xIt->second != yIt->second)
          return {xIt->first, yIt->first};
      }
    }

    return {-1, -1};
  }
};
