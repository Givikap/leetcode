using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> numsCounter;

    for (const int &num : nums)
      ++numsCounter[num];

    vector<pair<int, int>> numsCounterVector(numsCounter.begin(),
                                             numsCounter.end());

    sort(numsCounterVector.begin(), numsCounterVector.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           if (a.second != b.second)
             return a.second < b.second;

           return a.first > b.first;
         });

    vector<int> sortedNums;
    sortedNums.reserve(nums.size());

    for (const auto &[num, count] : numsCounterVector) {
      for (int _ = 0; _ < count; ++_)
        sortedNums.push_back(num);
    }

    return sortedNums;
  }
};
