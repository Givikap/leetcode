#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::string kthDistinct(std::vector<std::string> &arr, int k) {
    std::unordered_map<std::string, int> stringCounter;

    for (const std::string &s : arr)
      stringCounter[s]++;

    for (const std::string &s : arr) {
      if (stringCounter[s] == 1 && --k == 0)
        return s;
    }

    return "";
  }
};
