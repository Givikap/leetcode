#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int> getSneakyNumbers(std::vector<int> &nums) {
    std::unordered_set<int> numsSet;
    std::vector<int> sneakyNums;

    for (const int &num : nums) {
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
