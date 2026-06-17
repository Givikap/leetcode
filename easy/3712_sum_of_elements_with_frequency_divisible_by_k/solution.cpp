#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int sumDivisibleByK(std::vector<int> &nums, int k) {
    int numsCounter[101];
    for (const int &num : nums)
      ++numsCounter[num];

    int numsSum = 0;

    for (size_t i = 0; i < 101; ++i) {
      if (numsCounter[i] % k == 0)
        numsSum += i * numsCounter[i];
    }

    return numsSum;
  }
};
