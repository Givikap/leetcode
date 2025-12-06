using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, int> numsCounter;

    int maxFrequency = 0;
    int maxFrequencySum = 0;

    for (int &num : nums)
      if (++numsCounter[num] > maxFrequency)
        maxFrequency = numsCounter[num];

    for (unordered_map<int, int>::iterator it = numsCounter.begin(); it != numsCounter.end(); it++)
      if (it->second == maxFrequency)
        maxFrequencySum += maxFrequency;

    return maxFrequencySum;
  }
};
