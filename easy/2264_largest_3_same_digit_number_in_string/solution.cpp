using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  string largestGoodInteger(string num) {
    const vector<string> nums = {"999", "888", "777", "666", "555",
                                 "444", "333", "222", "111", "000"};

    for (const string &n : nums) {
      if (num.find(n) != string::npos)
        return n;
    }

    return "";
  }
};
