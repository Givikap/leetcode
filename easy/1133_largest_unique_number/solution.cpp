using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int largestUniqueNumber(vector<int> &nums) {
    unordered_map<int, int> numsCounter;

    for (const int &num : nums)
      ++numsCounter[num];

    int largestNum = -1;

    for (const auto &[num, count] : numsCounter) {
      if (count == 1)
        largestNum = max(num, largestNum);
    }

    return largestNum;
  }
};
