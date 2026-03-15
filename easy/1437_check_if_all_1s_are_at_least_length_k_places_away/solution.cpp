#include <vector>

class Solution {
public:
  bool kLengthApart(std::vector<int> &nums, int k) {
    int zerosCount = 1000001;

    for (const int &num : nums) {
      if (num == 1) {
        if (zerosCount < k)
          return false;
        zerosCount = 0;
      } else {
        zerosCount++;
      }
    }

    return true;
  }
};
