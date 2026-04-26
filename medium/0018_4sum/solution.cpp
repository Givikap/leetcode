#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    const size_t numsLen = nums.size();
    if (numsLen < 4)
      return {};

    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> fourSums;

    for (size_t outerLeft = 0; outerLeft < numsLen - 3; ++outerLeft) {
      if (outerLeft > 0 && nums[outerLeft] == nums[outerLeft - 1])
        continue;

      if ((long)nums[outerLeft] + nums[outerLeft + 1] + nums[outerLeft + 2] +
              nums[outerLeft + 3] >
          target)
        break;
      if ((long)nums[outerLeft] + nums[numsLen - 3] + nums[numsLen - 2] +
              nums[numsLen - 1] <
          target)
        continue;

      for (size_t innerLeft = outerLeft + 1; innerLeft < numsLen - 2;
           ++innerLeft) {
        if (innerLeft > outerLeft + 1 && nums[innerLeft] == nums[innerLeft - 1])
          continue;

        if ((long)nums[outerLeft] + nums[innerLeft] + nums[innerLeft + 1] +
                nums[innerLeft + 2] >
            target)
          break;
        if ((long)nums[outerLeft] + nums[innerLeft] + nums[numsLen - 2] +
                nums[numsLen - 1] <
            target)
          continue;

        size_t innerRight = innerLeft + 1;
        size_t outerRight = numsLen - 1;

        long leftSum = nums[outerLeft] + nums[innerLeft];

        while (innerRight < outerRight) {
          long currSum = leftSum + nums[innerRight] + nums[outerRight];

          if (currSum == target) {
            fourSums.push_back({nums[outerLeft], nums[innerLeft],
                                nums[innerRight], nums[outerRight]});

            while (innerRight < outerRight &&
                   nums[innerRight] == nums[innerRight + 1])
              ++innerRight;
            while (innerRight < outerRight &&
                   nums[outerRight] == nums[outerRight - 1])
              --outerRight;

            ++innerRight;
            --outerRight;
          } else if (currSum < target)
            ++innerRight;
          else
            --outerRight;
        }
      }
    }

    return fourSums;
  }
};
