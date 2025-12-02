using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    unordered_map<int, int> numsCounter;
    vector<int> sneakyNums;

    for (int &num : nums) {
      numsCounter[num] += 1;

      if (numsCounter[num] == 2) {
        sneakyNums.push_back(num);

        if (sneakyNums.size() == 2)
          return sneakyNums;
      }
    }

    return sneakyNums;
  }
};
