#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> arrayRankTransform(std::vector<int> &arr) {
    std::vector<int> arrCopy = arr;
    std::sort(arrCopy.begin(), arrCopy.end());

    std::unordered_map<int, int> rankMap;

    int rank = 0;
    for (const int &num : arrCopy) {
      if (rankMap.find(num) == rankMap.end())
        rankMap[num] = ++rank;
    }

    for (size_t i = 0; i < arr.size(); ++i)
      arr[i] = rankMap[arr[i]];

    return arr;
  }
};
