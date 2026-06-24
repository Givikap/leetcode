#include <set>
#include <vector>

class Solution {
public:
  std::vector<int> arrayRankTransform(std::vector<int> &arr) {
    std::set<int> arrSet(arr.begin(), arr.end());
    std::unordered_map<int, int> rankMap;

    int rank = 0;
    for (const int &num : arrSet)
      rankMap[num] = ++rank;

    for (size_t i = 0; i < arr.size(); ++i)
      arr[i] = rankMap[arr[i]];

    return arr;
  }
};
