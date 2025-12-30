using namespace std;

#include <cstddef>
#include <vector>

class Solution {
public:
  int longestMonotonicSubarray(vector<int> &nums) {
    const size_t numsLen = nums.size();

    bool increasing = false;
    bool decreasing = false;

    int prev, num;

    size_t subbarraySize = 1;
    size_t maxSubbarraySize = 1;

    for (size_t i = 1; i < numsLen; ++i) {
      prev = nums[i - 1];
      num = nums[i];

      if ((increasing && prev >= num) || (decreasing && prev <= num)) {
        increasing = false;
        decreasing = false;

        maxSubbarraySize = max(subbarraySize, maxSubbarraySize);
        subbarraySize = 1;
      }

      if (!increasing && prev < num)
        increasing = true;
      else if (!decreasing && prev > num)
        decreasing = true;

      if (increasing || decreasing)
        subbarraySize += 1;
    }

    return max(subbarraySize, maxSubbarraySize);
  }
};
