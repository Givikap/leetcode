#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> numsCounter;
    std::priority_queue<std::pair<int, int>> pq;
    std::vector<int> topKFreqientNums;

    for (const int &num : nums) {
      if (numsCounter.find(num) == numsCounter.end())
        numsCounter[num] = 1;
      else
        numsCounter[num]++;
    }

    for (std::unordered_map<int, int>::iterator it = numsCounter.begin();
         it != numsCounter.end(); ++it)
      pq.push(std::pair<int, int>(it->second, it->first));

    for (int _ = 0; _ < k; ++_) {
      topKFreqientNums.push_back(pq.top().second);
      pq.pop();
    }

    return topKFreqientNums;
  }
};
