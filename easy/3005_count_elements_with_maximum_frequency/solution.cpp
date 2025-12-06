using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, int> numsCounter;
    numsCounter.reserve(nums.size());

    int maxFrequency = 0;
    int maxFrequencyCount = 0;
    int numCount;

    for (int &num : nums) {
      numCount = ++numsCounter[num];

      if (numCount > maxFrequency) {
        maxFrequency = numsCounter[num];
        maxFrequencyCount = 1;
      } else if (numCount == maxFrequency) {
        maxFrequencyCount++;
      }
    }

    return maxFrequency * maxFrequencyCount;
  }
};
