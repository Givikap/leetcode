using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size();
  }
};
