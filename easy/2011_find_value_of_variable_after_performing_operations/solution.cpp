using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int finalValueAfterOperations(vector<string> &operations) {
    int finalValue = 0;

    for (string &operation : operations) {
      if (operation[0] == '+' || operation[2] == '+')
        finalValue++;
      else
        finalValue--;
    }

    return finalValue;
  }
};
