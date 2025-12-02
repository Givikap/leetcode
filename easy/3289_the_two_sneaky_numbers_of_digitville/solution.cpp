using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    unordered_set<int> numsSet;
    vector<int> sneakyNums;

    for (int &num : nums) {
      if (numsSet.find(num) != numsSet.end()) {
        sneakyNums.push_back(num);

        if (sneakyNums.size() == 2)
          break;
      } else {
        numsSet.insert(num);
      }
    }

    return sneakyNums;
  }
};
