#include <unordered_map>
#include <vector>

class Solution {
public:
  bool uniqueOccurrences(std::vector<int> &arr) {
    std::unordered_map<int, int> numsCounter;
    for (const int &num : arr)
      ++numsCounter[num];

    std::unordered_map<int, int> countsCounter;
    for (const auto &[_, count] : numsCounter)
      ++countsCounter[count];

    for (const auto &[_, count] : countsCounter)
      if (count != 1)
        return false;

    return true;
  }
};
