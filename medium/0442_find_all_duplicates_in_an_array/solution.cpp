using namespace std;

#include <vector>

class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> duplicates;

    for (const int &num : nums) {
      int idx = abs(num) - 1;

      if (nums[idx] < 0)
        duplicates.push_back(idx + 1);
      else
        nums[idx] *= -1;
    }

    return duplicates;
  }
};
