#include <unordered_map>
#include <vector>

class Solution {
public:
  int firstUniqueEven(std::vector<int> &nums) {
    std::unordered_map<int, int> numsCounter;
    for (const int &num : nums)
      ++numsCounter[num];

    for (const int &num : nums) {
      if (numsCounter[num] == 1 && num % 2 == 0)
        return num;
    }

    return -1;
  }
};
