#include <string>
#include <vector>

class Solution {
public:
  std::string largestGoodInteger(std::string num) {
    const std::vector<std::string> nums = {"999", "888", "777", "666", "555",
                                           "444", "333", "222", "111", "000"};

    for (const std::string &n : nums) {
      if (num.find(n) != std::string::npos)
        return n;
    }

    return "";
  }
};
