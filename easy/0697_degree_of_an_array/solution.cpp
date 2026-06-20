#include <unordered_map>
#include <vector>

class Solution {
public:
  int findShortestSubArray(std::vector<int> &nums) {
    std::unordered_map<int, int> numsCounter;
    for (const int &num : nums)
      ++numsCounter[num];

    const auto maxCountIt = std::max_element(
        numsCounter.begin(), numsCounter.end(),
        [](const auto &p1, const auto &p2) { return p1.second < p2.second; });

    const int maxCount = maxCountIt->second;
    if (maxCount == 1)
      return 1;

    const int numsLen = nums.size();
    int minLen = numsLen;

    for (const auto &[num, count] : numsCounter) {
      if (count == maxCount) {
        int left =
            std::distance(nums.begin(), find(nums.begin(), nums.end(), num));
        int right =
            std::distance(nums.begin(),
                          find(nums.rbegin(), nums.rend(), num).base()) -
            1;
        minLen = std::min(minLen, right - left + 1);
      }
    }

    return minLen;
  }
};
