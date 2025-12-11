using namespace std;

#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int maxSum(vector<int> &nums) {
    unordered_set<int> uniqueNums(nums.begin(), nums.end());

    vector<int> uniquePositiveNums;
    copy_if(uniqueNums.begin(), uniqueNums.end(),
            back_inserter(uniquePositiveNums), [](int num) { return num > 0; });

    if (uniquePositiveNums.size() == 0)
      return *max_element(nums.begin(), nums.end());

    return accumulate(uniquePositiveNums.begin(), uniquePositiveNums.end(), 0);
  }
};
