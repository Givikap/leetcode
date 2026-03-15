#include <string>
#include <vector>

class Solution {
public:
  int finalValueAfterOperations(std::vector<std::string> &operations) {
    int finalValue = 0;

    for (const std::string &operation : operations) {
      if (operation[0] == '+' || operation[2] == '+')
        finalValue++;
      else
        finalValue--;
    }

    return finalValue;
  }
};
