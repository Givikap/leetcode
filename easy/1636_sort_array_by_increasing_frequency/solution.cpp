using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> numsCounter;

    for (const int &num : nums)
      ++numsCounter[num];

    sort(nums.begin(), nums.end(), [&](const int &a, const int &b) {
      if (numsCounter[a] != numsCounter[b])
        return numsCounter[a] < numsCounter[b];

      return a > b;
    });

    return nums;
  }
};
