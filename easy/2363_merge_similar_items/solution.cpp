#include <map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  mergeSimilarItems(std::vector<std::vector<int>> &items1,
                    std::vector<std::vector<int>> &items2) {
    std::map<int, int> itemsMap;

    for (const std::vector<int> &item : items1)
      itemsMap[item[0]] += item[1];
    for (const std::vector<int> &item : items2)
      itemsMap[item[0]] += item[1];

    std::vector<std::vector<int>> mergedItems;
    mergedItems.reserve(itemsMap.size());

    for (const auto &[value, weight] : itemsMap)
      mergedItems.push_back(std::vector<int>{value, weight});

    return mergedItems;
  }
};
