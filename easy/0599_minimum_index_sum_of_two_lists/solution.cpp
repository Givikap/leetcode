#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> findRestaurant(std::vector<std::string> &list1,
                                          std::vector<std::string> &list2) {
    std::unordered_map<std::string, size_t> list1Map;
    for (size_t i = 0; i < list1.size(); ++i)
      list1Map[list1[i]] = i;

    size_t minIndex = UINT64_MAX;

    std::vector<std::string> commonRestaurants;

    for (size_t i = 0; i < list2.size(); ++i) {
      if (list1Map.find(list2[i]) != list1Map.end()) {
        size_t currIndex = i + list1Map[list2[i]];

        if (currIndex == minIndex)
          commonRestaurants.push_back(list2[i]);
        else if (currIndex < minIndex) {
          minIndex = currIndex;
          commonRestaurants = {list2[i]};
        }
      }
    }

    return commonRestaurants;
  }
};
