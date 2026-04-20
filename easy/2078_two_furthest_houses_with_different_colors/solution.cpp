#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxDistance(std::vector<int> &colors) {
    std::unordered_map<int, size_t> firstsMap;
    std::unordered_map<int, size_t> lastsMap;

    for (size_t i = 0, j = colors.size() - 1; i < colors.size(); ++i, --j) {
      if (firstsMap.find(colors[i]) == firstsMap.end())
        firstsMap[colors[i]] = i;
      if (lastsMap.find(colors[j]) == lastsMap.end())
        lastsMap[colors[j]] = j;
    }

    int maxDist = 1;

    for (const auto &[_, i] : firstsMap) {
      for (const auto &[_, j] : lastsMap) {
        if (colors[i] != colors[j])
          maxDist = std::max(maxDist, std::abs((int)(i - j)));
      }
    }

    return maxDist;
  }
};
