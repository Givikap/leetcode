#include <vector>

class Solution {
public:
  std::vector<bool> prefixesDivBy5(std::vector<int> &nums) {
    int val = 0;
    std::vector<bool> answer;

    for (int i = 0; i < nums.size(); i++) {
      val = (val * 2 + nums[i]) % 5;
      answer.push_back(val == 0);
    }

    return answer;
  }
};
