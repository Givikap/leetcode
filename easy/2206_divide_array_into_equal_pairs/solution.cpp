using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  bool divideArray(vector<int> &nums) {
    unordered_map<int, int> numsCounter;

    for (const int &num : nums)
      ++numsCounter[num];

    for (auto &[_, count] : numsCounter) {
      if (count % 2 == 1)
        return false;
    }

    return true;
  }
};
