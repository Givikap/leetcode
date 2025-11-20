using namespace std;

#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> numsCounter;
    priority_queue<pair<int, int>> pq;
    vector<int> topKFreqientNums;

    for (int &num : nums) {
      if (numsCounter.find(num) == numsCounter.end())
        numsCounter[num] = 1;
      else
        numsCounter[num]++;
    }

    for (unordered_map<int, int>::iterator it = numsCounter.begin();
         it != numsCounter.end(); ++it)
      pq.push(pair<int, int>(it->second, it->first));

    for (int i = 0; i < k; i++) {
      topKFreqientNums.push_back(pq.top().second);
      pq.pop();
    }

    return topKFreqientNums;
  }
};
