#include <vector>

class Solution {
public:
  std::vector<int> findErrorNums(std::vector<int> &nums) {
    const int numsLen = nums.size();

    std::vector<int> notSeen;
    for (int i = 0; i < numsLen + 1; ++i)
      notSeen.push_back(i);

    int duplicate, mismatch;

    for (const int &num : nums) {
      if (notSeen[num])
        notSeen[num] = 0;
      else
        duplicate = num;
    }

    for (const int &num : notSeen) {
      if (num) {
        mismatch = num;
        break;
      }
    }

    return {duplicate, mismatch};
  }
};
